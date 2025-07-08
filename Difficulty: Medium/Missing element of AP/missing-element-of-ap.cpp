// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int start=arr[0];
        int n=arr.size();
        // int d=arr[1]-arr[0];
        // int d=min(arr[1]-arr[0],arr[n-1]-arr[n-2]);
        int d1=arr[1]-arr[0];int d2=arr[n-1]-arr[n-2];
        int d=0;
        if(abs(d1)<abs(d2))d=d1;
        else d=d2;
        int low=0;int high=arr.size()-1;int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long val_mid=arr[mid];
            long long actual_mid=start+(mid)*d;
            if(val_mid==actual_mid)low=mid+1;
            else{
                ans=actual_mid;
                high=mid-1;
            }
        }
        return ans!=-1?ans:(start+(n)*d);
    }
};