// User function Template for C++

class Solution {
  public:
  
    int solve(int i,int w,vector<int> & wt,vector<int> &val,vector<vector<int>> &dp){
        // if(i<0)return -1e8;
        if(i==0){
            return (w/wt[0])*val[0];
        }
        if(dp[i][w]!=-1)return dp[i][w];
        int take=-1e8;
        if(wt[i]<=w)take=val[i]+solve(i,w-wt[i],wt,val,dp);
        int nottake=solve(i-1,w,wt,val,dp);
        return dp[i][w]=max(take,nottake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int m=val.size();
        vector<vector<int>> dp(m,vector<int>(capacity+1,-1));
        return solve(m-1,capacity,wt,val,dp);
    }
};