class Solution {
  public:
    int checknext(int i,vector<vector<int>>&arr){
        if(i==arr.size())return -1;
        int curr=arr[i][1];
        int l=i+1;int h=arr.size()-1;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(mid>i && mid<arr.size()){
               if(arr[mid][0]>=curr){
                ans=mid;
                h=mid-1;
               }
               else l=mid+1; 
            }
            // cout<<mid<<" "<<endl;
        }
        return ans;
    }
    int check(vector<vector<int>> &arr,int i,vector<int> &dp){
        if(i==arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int next=checknext(i,arr);
        int take=arr[i][2];
        // if(next!=-1){
        //   take= 
        // }
        //take
        if(next!=-1)take=take+check(arr,next,dp);
        
        //int nottake
        int nottake=check(arr,i+1,dp);
        return dp[i]=max(take,nottake);
    }
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        vector<int> dp(jobs.size()+1,-1);
        sort(jobs.begin(),jobs.end());
        // for(int i=0;i<jobs.size();i++){
        //     arr.push_back(arr[i][2]);
        // }
        // bool cmp(const vector<int>& a, const vector<int>& b) {
        //      return a[0] < b[0];   // sort by 3rd element
        // }
        // sort(arr,begin(),arr.end(),cmp);

        // int low=*min_element(arr.begin(),arr.end());
        // int high=accumulate(arr.begin(),arr.end(),0);
        // int mini=low;
        // while(low<high){
        //     int mid=(low+high)/2;
        //     if(check(mid,jobs)){
        //         mini=mid;
        //         low=mid+1;
        //     }
        //     else high=mid-1;
        // }
        return check(jobs,0,dp);
        // return mini;
    }
};
