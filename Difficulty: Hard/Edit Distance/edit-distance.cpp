class Solution {
  public:
    int solve(int i,int j,string &x,string &y,vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        int cnt=INT_MAX;
        if(x[i]==y[j]){
            cnt=min(cnt,solve(i-1,j-1,x,y,dp));
        }
        else{
           cnt=1+min({cnt,solve(i-1,j,x,y,dp),solve(i,j-1,x,y,dp),solve(i-1,j-1,x,y,dp)}); 
        }
        return dp[i][j]=cnt;
    }
    // Function to compute the edit distance between two strings
    int editDistance(string& x, string& y) {
        // code here
        int m=x.size();
        int n=y.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,x,y,dp);
    }
};