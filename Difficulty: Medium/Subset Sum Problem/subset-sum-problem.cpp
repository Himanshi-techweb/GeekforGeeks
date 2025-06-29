class Solution {
  public:
    bool check(int i,vector<int> &arr,int sum,vector<vector<int>>&dp){
        if(sum==0)return true;
        if(i==0){
            return sum==arr[0];
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool taken=false;
        if(sum>=arr[i]) taken=check(i-1,arr,sum-arr[i],dp);
        bool nottaken=check(i-1,arr,sum,dp);
        return dp[i][sum]=taken||nottaken;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int m=arr.size();
        vector<vector<int>> dp(m,vector<int>(sum+1,-1));
        return check(arr.size()-1,arr,sum,dp);
        
        
    }
};