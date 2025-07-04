class Solution {
  public:
    bool check(int mid,vector<int> &arr,int k){
       int cnt=0;
       for(auto it:arr){
          if(it<mid)cnt=cnt+1;
          else if(it%mid==0)cnt+=it/mid;
          else {
              cnt=cnt+(it/mid)+1;
          }
       }
       return cnt<=k;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        int hour=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,arr,k)){
                hour=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return hour;
    }
};