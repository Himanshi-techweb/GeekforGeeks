class Solution {
  public:
    int numberofLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> check(n,1);
        vector<int> dp(n,1);
        vector<int> back(n);
        int maxi=1;
        for(int i=0;i<n;i++)back[i]=i;
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev]){
                   if(dp[i]<dp[prev]+1 ){
                       dp[i]=1+dp[prev];
                       back[i]=prev;
                       check[i]=check[prev];
                   }
                   else if(dp[i]==dp[prev]+1){
                       check[i]+=check[prev];
                   }
                   
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)ans+=check[i];
        }
        return ans;
    }
};