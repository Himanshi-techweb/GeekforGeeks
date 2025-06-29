// User function Template for C++

class Solution {
  public:
    int solve(int i,int length,vector<int> & price,vector<vector<int>>&dp){
        if(i==0 ){
            return (length)*price[0];
        }
        if(dp[i][length]!=-1)return dp[i][length];
        int take=-1e8;
        if(i+1<=length)take=price[i]+solve(i,length-i-1,price,dp);
        int nottake=solve(i-1,length,price,dp);
        return dp[i][length]=max(take,nottake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int length=price.size();
        vector<vector<int>> dp(length,vector<int> (length+1,-1));
        return solve(length-1,length,price,dp);
    }
};