// User function template for C++

class Solution {
  public:
    bool check(int mid,vector<int>&arr,int k){
        int cnt=1;int sum=0;
        for(auto it:arr){
           if(it>mid)return false;
           if(sum+it<=mid){
               sum=sum+it;
           } 
           else{
               cnt++;
               sum=it;
           }
        }
        return cnt<=k;
    }
    int minTime(vector<int>& arr, int k) {
      int low=*min_element(arr.begin(),arr.end());
      int high=accumulate(arr.begin(),arr.end(),0);
      int t=high;
      if(k==1)return high;
      while(low<=high){
          int mid=low+(high-low)/2;
          if(check(mid,arr,k)){
              t=mid;
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      return t;
    }
};