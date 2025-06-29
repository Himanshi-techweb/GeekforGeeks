class Solution {
  public:
    int find(int i,vector<int> &arr,vector<int> &dp){
       if(i==arr.size()-1)return 0;
       if(dp[i]!=-1)return dp[i];
       int jump_1=INT_MAX;
       if(i+1<arr.size())jump_1=min(jump_1,abs(arr[i]-arr[i+1])+find(i+1,arr,dp));
       int jump_2=INT_MAX;
       if(i+2<arr.size())jump_2=min(jump_2,abs(arr[i]-arr[i+2])+find(i+2,arr,dp));
       return dp[i]=min(jump_1,jump_2);
    }
    int minCost(vector<int>& height) {
        int n=height.size();
       vector<int> dp(n,-1);
       return find(0,height,dp);
    }
};