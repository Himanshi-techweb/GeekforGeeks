//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int solve(int i,int W,vector<int> & wt,vector<int> & arr,vector<vector<int>> &dp){
        // if(wt[i]>W)return 0;
        if(i==0 ){
            if(wt[i]<=W)return (W/wt[i])*arr[i];
            else return 0;
        }
        if(dp[i][W]!=-1)return dp[i][W];
        int take=0;
        if(W>=wt[i]){
          take=arr[i]+solve(i,W-wt[i],wt,arr,dp);  
        }
        int nottake=0+solve(i-1,W,wt,arr,dp);
        return dp[i][W]=max(take,nottake);
        
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        int W=capacity;
        vector<vector<int>> dp(n,vector<int> (capacity+1,0));
        for(int w=0;w<=W;w++){
            dp[0][w]=(w/wt[0])*val[0];
        }
        for(int i=1;i<val.size();i++){
            for(int w=0;w<=W;w++){
              int take=0;
              if(w>=wt[i]){
                 take=val[i]+dp[i][w-wt[i]];  
              }
              int nottake=0+dp[i-1][w];
              dp[i][w]=max(take,nottake);  
            }
        }
        return dp[wt.size()-1][W];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends