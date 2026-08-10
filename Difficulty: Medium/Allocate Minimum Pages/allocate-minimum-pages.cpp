class Solution {
  public:
    bool solve(long long mid,vector<int>&arr,int k){
        int cnt=0;long long sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid)return false;
            if(sum+arr[i]>mid){
                cnt++;
                sum=arr[i];
            }
            else sum+=arr[i];
        }
        if(sum<=mid)cnt++;
        
        // cout<<mid<<" "<<cnt<<endl;
        return cnt<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        // sort(arr.begin(),arr.end());
        if(k>arr.size())return -1;
        int l=*min_element(arr.begin(),arr.end());
        long long h=accumulate(arr.begin(),arr.end(),0LL);
        int ans=-1;
        while(l<=h){
            long long mid=(l+h)/2;
            if(solve(mid,arr,k)){
               ans=mid;
               h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};