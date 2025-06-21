// User function Template for C++

class Solution {
  public:
    int solve(int i,int j,vector<vector<int>> & mat,vector<vector<int>>&dp){
        if(i<0 || j<0 || j>=mat[0].size())return INT_MIN;
        if(i==0)return dp[0][j]=mat[0][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int left=solve(i-1,j-1,mat,dp);
        int just=solve(i-1,j,mat,dp);
        int right=solve(i-1,j+1,mat,dp);
        return dp[i][j]=mat[i][j]+max({left,just,right});
    }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[m-1][i]=solve(m-1,i,mat,dp);
        }
        return *max_element(dp[m-1].begin(),dp[m-1].end());
    }
};