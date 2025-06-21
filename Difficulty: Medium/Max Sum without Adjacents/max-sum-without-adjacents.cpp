// User function template for C++
class Solution {
  public:
    int solve(int i,vector<int> &arr,vector<int> &dp){
        if(i==0)return arr[0];
        if(dp[i]!=-1)return dp[i];
        // int taken=INT_MIN;
        int taken=arr[i]+solve(i-2,arr,dp);
        int nottaken=solve(i-1,arr,dp);
        return dp[i]=max(taken,nottaken);
    }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n+1,-1);
        solve(n-1,arr,dp);
        return dp[n-1];
    }
};