class Solution {
  public:
    int solve(int i,int task,vector<vector<int>>&arr,vector<vector<int>>&dp){
        if(i==0){
            int maxi=0;
            for(int j=0;j<3;j++){
                if(j!=task){
                    maxi=max(maxi,arr[0][j]);
                }
            }
            return dp[0][task]=maxi;
        }
        if(dp[i][task]!=-1)return dp[i][task];
        int merit=0;
        for(int j=0;j<3;j++){
            if(j!=task){
                int point=arr[i][j]+solve(i-1,j,arr,dp);
                merit=max(merit,point);
            }
        }
        return dp[i][task]=merit;
        
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        // return solve(n-1,3,arr);
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        int a=solve(n-1,0,arr,dp);
        int b=solve(n-1,1,arr,dp);
        int c=solve(n-1,2,arr,dp);
        return max({dp[n-1][1],dp[n-1][0],dp[n-1][2]});
    }
};