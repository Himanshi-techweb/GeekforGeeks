class Solution {
  public:
    int solve(int i,int buy,int k,vector<vector<vector<int>>> &dp,vector<int> &price){
        if(i>=price.size())return 0;
        if(k<=0)return 0;
        if(dp[i][k][buy]!=-1)return dp[i][k][buy];
        int profit=0;
        profit=solve(i+1,buy,k,dp,price);
        if(buy){//buy==0
           profit=max(profit,-price[i]+solve(i+1,0,k,dp,price));
        }
        else{
            profit=max(profit,price[i]+solve(i+1,1,k-1,dp,price));
        }
        return dp[i][k][buy]=profit;
    }
    int maxProfit(vector<int>& price, int k) {
        // code here
        int n=price.size();
        int x=k;
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (k+1,vector<int>(2,-1)));
        return solve(0,1,x,dp,price);
    }
};