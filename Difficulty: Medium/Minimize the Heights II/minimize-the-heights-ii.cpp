// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int maxi,mini;int ans=arr[arr.size()-1]-arr[0];
        for(int i=0;i<arr.size()-1;i++){
            maxi=max(arr[arr.size()-1]-k,arr[i]+k);
            mini=min(arr[0]+k,arr[i+1]-k);
            if( mini<0)continue;
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};