//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int idx,int task,vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(idx==0){
            int maxi=0;
            for(int i=0;i<=2;i++){
                if(i!=task){
                  maxi=max(maxi,arr[0][i]);  
                }
            }
            return maxi;
        }
        if(dp[idx][task]!=0)return dp[idx][task];
        int ans=0;
        for(int i=0;i<=2;i++){
          if(i!=task){
              int check=arr[idx][i]+solve(idx-1,i,arr,dp);
              ans=max(ans,check);
          }
        }
        return dp[idx][task]=ans;
    }
    int maximumPoints(vector<vector<int>>& arr) {
      int n=arr.size();
      vector<vector<int>> dp(n+1,vector<int> (4,0));
      return solve(n-1,3,arr,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends