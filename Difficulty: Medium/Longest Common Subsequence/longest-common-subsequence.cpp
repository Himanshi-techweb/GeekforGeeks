class Solution {
  public:
    int solve(int i,int j,string x,string y,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==0 && j==0)return x[i]==y[j];
        //match
        int match=0;
        if(x[i]==y[j]){
            match=max(match,1+solve(i-1,j-1,x,y,dp));
        }
        else{
            match=max(match,max(solve(i,j-1,x,y,dp),solve(i-1,j,x,y,dp)));
        }
        return dp[i][j]=match;
    }
    int lcs(string x, string y) {
        vector<vector<int>> dp(x.size(),vector<int> (y.size(),0));
        // return solve(text1.size()-1,text2.size()-1,text1,text2,dp);
        if(x[0]==y[0])dp[0][0]=1;
        for(int i=0;i<x.size();i++){
            for(int j=0;j<y.size();j++){
                // if(i==0 && j==0)continue;
                int match=0;
                if(x[i]==y[j]){
                 if(i>0 && j>0)match=1+dp[i-1][j-1];
                 else match=1;
                 
                }
                else{
                 if(j>0)match=max(match,dp[i][j-1]);
                 if(i>0)match=max(match,dp[i-1][j]);
                }
                dp[i][j]=match; 
            }
        }
        return dp[x.size()-1][y.size()-1];
    }
};
