// User function Template for C++

class Solution {
  public:
    int solve(int i,vector<int> &arr,int k,vector<int> &dp){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int currlen=0;int mincost=INT_MAX;
        for(int j=i;j<arr.size();j++){
            currlen+=arr[j];
            if(j>i)currlen+=1;
            if(currlen>k)break;
            int cost=(j==arr.size()-1)?0:(k-currlen)*(k-currlen);
            int totalcost=cost+solve(j+1,arr,k,dp);
            mincost=min(mincost,totalcost);
        }
        return dp[i]=mincost;
    }
    int solveWordWrap(vector<int> arr, int k) {
        // Code here
        vector<int> dp(arr.size(),-1);
        return solve(0,arr,k,dp);
    }
};