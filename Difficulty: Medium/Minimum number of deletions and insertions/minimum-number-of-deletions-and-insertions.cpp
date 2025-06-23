//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int minOperations(string &x, string &y) {
       int m=x.size();
       int n=y.size();
       vector<vector<int>> dp(m+1,vector<int> (n+1,0));
       vector<int> prev(n+1,0);
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        } 
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        } 
        for(int i=1;i<=m;i++){
          for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1])dp[i][j]= 1+dp[i-1][j-1];
            else{
              int left=dp[i-1][j];
              int right=dp[i][j-1];
              dp[i][j]= max(left,right);
            }
          }
        }
        int common= dp[m][n];
        int total_size=m+n;
        return total_size-2*common;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        cout << ob.minOperations(s1, s2) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends