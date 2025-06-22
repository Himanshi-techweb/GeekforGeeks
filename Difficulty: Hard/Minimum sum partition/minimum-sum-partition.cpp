class Solution {

  public:
    bool check(int i,vector<int> &arr,int tar,vector<vector<int>> &dp){
      if(tar==0)return true;
    //   if(i<0 || tar<0)return false;
      if(i==0)return tar==arr[0];
      if(dp[i][tar]!=-1)return dp[i][tar];
      bool taken=false;
      if(arr[i]<=tar)taken=check(i-1,arr,tar-arr[i],dp);
      bool nottaken=check(i-1,arr,tar,dp);
      return dp[i][tar]=taken|| nottaken;
    }
    int minDifference(vector<int>& arr) {
        // code here
        int m=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        vector<vector<bool>> dp(m,vector<bool>(sum+1,false));
        for(int i=0;i<m;i++){
            dp[i][0]=true;
        }
        if(arr[0]<=sum)dp[0][arr[0]]=true;
        for(int i=1;i<m;i++){
            for(int j=0;j<=sum;j++){
                bool taken=false;
                if(arr[i]<=j)taken=dp[i-1][j-arr[i]];
                bool nottaken=dp[i-1][j];
                dp[i][j]=taken|| nottaken; 
            }
        }
        int mini=INT_MAX;int subset1=0;int subset2=0;
        for(int i=0;i<=sum/2;i++){
           if(dp[m-1][i]==true){
               subset1=i;
               subset2=sum-i;
               mini=min(mini,abs(subset1-subset2));
           } 
        }
        return mini;
    }
};
