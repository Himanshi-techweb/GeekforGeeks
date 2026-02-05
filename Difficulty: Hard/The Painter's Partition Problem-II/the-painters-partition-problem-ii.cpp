class Solution {
  public:
    bool check(int mid,int k,vector<int> &arr){
        int count=0;int sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>mid){
                count++;
                sum=arr[i];
            }
            else sum=sum+arr[i];
        }
        count++;
        return count<=k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,k,arr)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};