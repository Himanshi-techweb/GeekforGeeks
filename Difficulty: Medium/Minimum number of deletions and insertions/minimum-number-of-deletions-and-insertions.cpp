//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int minOperations(string &t1, string &t2) {
      int n1=t1.size();
      int n2=t2.size();
      int k=n1+n2;
     vector<vector<int>>dp(n1+1,vector<int> (n2+1,0));
    // vector<int> prev(n2+1,0);
    // vector<int> curr(n2+1,0);
      for(int i=0;i<=n1;i++){
        dp[i][0]=0;
      }
      for(int i=0;i<=n2;i++){
        dp[0][i]=0;
      }
    // prev[0]=curr[0]=0;
      for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(t1[i-1]==t2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        // prev=curr;
      } 
      return k-2*dp[n1][n2];
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