class Solution {
  public:
    int solve(int i,int task,vector<vector<int>>&arr,vector<vector<int>>&dp){
       if(i<0)return 0;
    //   if(i==0 && task==0) return max(arr[i][1],arr[i][2]);
    //   else if(i==0 && task==1) return max(arr[i][0],arr[i][2]);
    //   else if(i==0 && task==2) return max(arr[i][1],arr[i][0]); mistake
       if(i==0){
           int maxi=0;
           for(int k=0;k<3;k++){
               if(k!=task){
                   maxi=max(maxi,arr[0][k]);
               }
           }
           return maxi;
       }
       if(dp[i][task]!=-1)return dp[i][task];
       int point=INT_MIN;
       //running taken
       if(task==0){
           point=max(point,max(arr[i][1]+solve(i-1,1,arr,dp),arr[i][2]+solve(i-1,2,arr,dp)));
       }
       else if(task==1){
           point =max(point,max(arr[i][2]+solve(i-1,2,arr,dp),arr[i][0]+solve(i-1,0,arr,dp)));
       }
       else if(task==2){
           point=max(point,max(arr[i][0]+solve(i-1,0,arr,dp),arr[i][1]+solve(i-1,1,arr,dp)));
       }
       else{
           point=max({arr[i][0]+solve(i-1,0,arr,dp),arr[i][1]+solve(i-1,1,arr,dp),arr[i][2]+solve(i-1,2,arr,dp)});
       }
       return dp[i][task]=point;
        
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
       vector<vector<int>> dp(arr.size(),vector<int> (4,-1));
       return solve(arr.size()-1,3,arr,dp);
    }
};