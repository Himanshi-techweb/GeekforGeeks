class Solution {
  public:
    int check(int i,int sum,vector<int> &arr,vector<vector<int>> &dp){
        if(i==0){
           if(arr[0]==sum && sum==0)return 2;
           else if(sum==0 || arr[0]==sum )return 1;
           else return 0;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int taken=0;
        if(sum>=arr[i])taken=check(i-1,sum-arr[i],arr,dp);
        int nottaken=check(i-1,sum,arr,dp);
        return dp[i][sum]=taken+nottaken;
    }
    int perfectSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>> dp(arr.size(),vector<int> (sum+1,-1)); 
        return check(arr.size()-1,sum,arr,dp);
    }
};