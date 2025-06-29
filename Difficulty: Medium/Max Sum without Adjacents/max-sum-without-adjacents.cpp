// User function template for C++
class Solution {
  public:
    int sum(int i,vector<int> &arr,vector<int> &dp){
        if(i>=arr.size())return 0;
        if(i==arr.size()-1)return arr[i];
        if(dp[i]!=-1)return dp[i];
        int take=INT_MIN;
        take=arr[i]+sum(i+2,arr,dp);
        int nottake=INT_MIN;
        nottake=sum(i+1,arr,dp);
        return dp[i]=max(take,nottake);
    }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return sum(0,arr,dp);
    }
};