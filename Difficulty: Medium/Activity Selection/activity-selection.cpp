class Solution {
  public:
    vector<int> dp;
    int solve(int i,vector<vector<int>>&arr){
        if(i>=arr.size())return 0;
        int next=-1;int l=i+1;int h=arr.size()-1;
        if(dp[i]!=-1)return dp[i];
        while(l<=h){
            int m=(l+h)/2;
            if(arr[m][0]>arr[i][1]){
                next=m;
                h=m-1;
            }
            else l=m+1;
        }
        
        int take=1+((next!=-1)?solve(next,arr):0);
        int nottake=solve(i+1,arr);
        return dp[i]=max(dp[i],max(take,nottake));
        
    }
    int activitySelection(vector<int> &start, vector<int> &start1) {
        // code here
        vector<vector<int>> arr;
        dp.resize(start.size(),-1);
        for(int i=0;i<start.size();i++){
            arr.push_back({start[i],start1[i]});
        }
        sort(arr.begin(),arr.end());
        return solve(0,arr);
        
    }
};