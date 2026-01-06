// User function Template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int ans=arr[arr.size()-1]-arr[0];
        int mini=arr[0];int maxi=arr[arr.size()-1];
        int i=0;
        while(i<arr.size()-1){
            mini=min(arr[0]+k,arr[i+1]-k);
            maxi=max(arr[arr.size()-1]-k,arr[i]+k);
            ans=min(maxi-mini,ans);
            i++;
        }
        // ans=min(ans,b[arr.size()-1]-a[i]);
            
        
        return ans;
    }
};