class Solution {
  public:
    int solve(int i,int w,vector<int> &val,vector<int> &wt,vector<vector<int>>&dp){
        if(i==0){
            if(wt[0]<=w)return val[0];
            return 0;
        }
        if(dp[i][w]!=-1)return dp[i][w];
        int take=0;
        if(w>=wt[i])take= val[i]+solve(i-1,w-wt[i],val,wt,dp);
        int nottake=solve(i-1,w,val,wt,dp);
        return dp[i][w]=max(take,nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
       int m=val.size();
       vector<vector<int>> dp(m,vector<int> (W+1,-1));
       return solve(m-1,W,val,wt,dp);
    }
};