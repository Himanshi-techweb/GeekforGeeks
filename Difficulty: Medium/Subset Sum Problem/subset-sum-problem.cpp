class Solution {
  public:
    bool check(int i,vector<int> &arr,int tar,vector<vector<int>> &dp){
      if(tar==0)return true;
      if(i<0 || tar<0)return false;
      if(dp[i][tar]!=-1)return dp[i][tar];
      bool taken=check(i-1,arr,tar-arr[i],dp);
      bool nottaken=check(i-1,arr,tar,dp);
      return dp[i][tar]=taken|| nottaken;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int m=arr.size();
        vector<vector<int>> dp(m,vector<int>(sum+1,-1));
        return check(arr.size()-1,arr,sum,dp);
    }
};