// User function Template for C++

class Solution {
  public:
    int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>> &dp){
        if(i<0 || j<0 || j>=arr[0].size())return INT_MIN;
        if(i==0)return arr[0][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int left=INT_MIN;
        int right=INT_MIN;
        int above=INT_MIN;
        left=solve(i-1,j-1,arr,dp);
        right=solve(i-1,j+1,arr,dp);
        above=solve(i-1,j,arr,dp);
        return dp[i][j]=arr[i][j]+max({left,right,above});
    }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int j=0;j<n;j++){
            dp[m-1][j]=solve(m-1,j,mat,dp);
        }
        return *max_element(dp[m-1].begin(),dp[m-1].end());
    }
};