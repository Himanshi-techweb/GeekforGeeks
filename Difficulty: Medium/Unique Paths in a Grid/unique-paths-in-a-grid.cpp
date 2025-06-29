class Solution {
  public:
    int solve(int i,int j,vector<vector<int>> &arr,vector<vector<int>>&dp){
        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=0;
        if(j-1>=0 && arr[i][j-1]==0) left=solve(i,j-1,arr,dp);
        int above=0;
        if(i-1>=0 && arr[i-1][j]==0)above=solve(i-1,j,arr,dp);
        return dp[i][j]=left+above;
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // //code here
        int m=grid.size();
        int n=grid[0].size();
        
        if(grid[0][0]==1 || grid[m-1][n-1]==1)return 0;
        vector<vector<int>> dp(m+1,vector<int> (n,-1));
        return solve(m-1,n-1,grid,dp);
        
        
    }
    

};