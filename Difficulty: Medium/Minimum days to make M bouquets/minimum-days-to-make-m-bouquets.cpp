class Solution {
  public:
    bool check(int mid,vector<int> &arr,int m,int k){
        int cnt=0;int ans=0;
        for(auto it:arr){
          if(it<=mid){
            cnt++;  
          }
          else{
              ans+=(cnt/k);
              cnt=0;
          }
        }
        if(cnt!=0)ans+=(cnt/k);
        return ans>=m;
    }
    int minDaysBloom(int m, int k, vector<int> &arr) {
        // Code here
        int low=*min_element(arr.begin(),arr.end());
        int high=*max_element(arr.begin(),arr.end());
        int day=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,arr,m,k)){
                day=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return day;
    }
};