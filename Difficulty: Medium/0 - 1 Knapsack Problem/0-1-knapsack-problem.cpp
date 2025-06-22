class Solution {
  public:
    int solve(int i,int w,vector<int> &val,vector<int> &wt,vector<vector<int>>&dp){
        if(i==0 ){
            return (wt[0]<=w)?val[0]:0;
        }
        if(dp[i][w]!=-1)return dp[i][w];
        int take=INT_MIN;int nottake=INT_MIN;
        if(w-wt[i]>=0) take=val[i]+solve(i-1,w-wt[i],val,wt,dp);
        nottake=solve(i-1,w,val,wt,dp);
        return dp[i][w]=max(take,nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
       int m=val.size();
       vector<vector<int>> dp(m,vector<int> (W+1,-1));
       return solve(m-1,W,val,wt,dp);
    }
};