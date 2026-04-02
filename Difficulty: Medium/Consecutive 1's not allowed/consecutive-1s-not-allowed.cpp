class Solution {
  public:
    vector<vector<int>>dp;
    int count(int i,int n,int back){
        if(i==n)return 1;
        if(dp[i][back+1]!=-1)return dp[i][back+1];
        int way=0;
        //check if back was 1 then cannot take 1 again only take 0
        //if back was 0 then can take  0 or 1
        int x=count(i+1,n,0);
        if(back==1){
            way+=x;
        }
        else{
            way+=(x+count(i+1,n,1));
        }
        return dp[i][back+1]=way;
        
    }
    int countStrings(int n) {
        // code here
        dp.assign(n+1,vector<int>(3,-1));
        //check what was previous bit if it bit then change it
        return count(0,n,-1);
    }
};