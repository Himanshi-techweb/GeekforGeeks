// User function template for C++

class Solution {
  public:
    bool check(vector<int> &arr,int mid,int k){
        int cnt=1;int sum=0;
        for(auto x:arr){
            if(x>mid)return false;
           if(sum+x<=mid){
             sum+=x;   
           }
           else{
               cnt++;
               sum=x;
           }
        }
        //if(sum!=0)cnt++;
        return cnt<=k;
        
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        //sort(arr.begin(),arr.end());
        int low=*min_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(low<=high){
           int mid=low+(high-low)/2;
           if(check(arr,mid,k)){
               ans=mid;
               high=mid-1;
           }
           else{
               low=mid+1;
           }
        }
        // return minimum time
        return ans;
    }
};