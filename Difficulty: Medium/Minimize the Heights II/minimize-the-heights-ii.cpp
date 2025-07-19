// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-k<0)continue;
            int maxi=max(arr[n-1]-k,arr[i]+k);
            int mini=min(arr[0]+k,arr[i+1]-k);
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};