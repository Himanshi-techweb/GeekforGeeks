class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> back(n);
        vector<int> ans;
        for(int i=0;i<back.size();i++)back[i]=i;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev] && dp[i]<1+dp[prev]){
                   dp[i]=1+dp[prev];
                   back[i]=prev;
                }
            }
        }int ix=0;int maxi=dp[0];
        for(int i=1;i<dp.size();i++){
           if(dp[i]>maxi){
               ix=i;
               maxi=dp[i];
           } 
        }
        ans.push_back(arr[ix]);
        while(ix!=back[ix]){
           ix=back[ix];
           ans.push_back(arr[ix]);
        }
        // ans.push_back(arr[ix]);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};