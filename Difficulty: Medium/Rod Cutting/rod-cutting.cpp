//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int solve(int i,int l,vector<int> &arr,vector<vector<int>>&dp){
        // if(l==0)return 0;
        if(i==0){
          return (l)*arr[0];  
        }
        if(dp[i][l]!=-1)return dp[i][l];
        int take=0;
        if(i+1<=l ){
            take=arr[i]+solve(i,l-(i+1),arr,dp);
        }
        int nottake=0+solve(i-1,l,arr,dp);
        return dp[i][l]=max(take,nottake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solve(n-1,n,price,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends