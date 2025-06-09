class Solution {
  public:
    bool check(int mid,int k,vector<int> &arr){
        int cnt=1;int sum=0;
        for(auto x:arr){
            if(x>mid)return false;
            if(sum+x>mid){
                cnt++;
                sum=x;
            }
            else{
                sum+=x;
            }
        }
        return (cnt<=k);
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k){
          return -1;  
        }
        int low=*min_element(arr.begin(),arr.end());int ans=0;
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=low + (high-low)/2;
            if(check(mid,k,arr)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
                
            }
        }
        return ans;
    }
};