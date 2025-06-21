// User function Template for C++
class Solution {
  public:
    int fibonacci(int i,vector<int> &dp){
        if(i==0 || i==1)return i;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=fibonacci(i-1,dp)+fibonacci(i-2,dp);
    }
    int nthFibonacci(int n) {
        // code here
        vector<int> dp(n+1,-1);
        // dp[0]=0;
        // dp[1]=1;
        if(n==0 || n==1)return n;
        fibonacci(n,dp);
        return dp[n];
    }
};