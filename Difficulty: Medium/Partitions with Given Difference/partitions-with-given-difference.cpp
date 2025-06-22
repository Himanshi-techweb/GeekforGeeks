class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int m=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        int cnt=0;
        int target=sum+d;
        vector<vector<int>> dp(m,vector<int>(target+1,0));
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        
        if(target%2!=0)return 0;
        if(arr[0]<=target)dp[0][arr[0]]+=1;
        for(int i=1;i<m;i++){
            for(int j=0;j<=target;j++){
                int taken=0;
                if(arr[i]<=j)taken=dp[i-1][j-arr[i]];
                int nottaken=dp[i-1][j];
                dp[i][j]=taken + nottaken;
            }
        }
        if(target%2==0){
            target=target/2;
                cnt+=dp[m-1][target];
        }
        return cnt;
    }
};