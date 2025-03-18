//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<vector<int>> check(n);
        for(int i=0;i<n;i++){
           check[i].push_back(arr[i]);
        }
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
           for(int j=0;j<i;j++){
              if(arr[i]>arr[j]){
                  if(dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    check[i]=check[j];
                    check[i].push_back(arr[i]);
                  }
              }
           }
        }
        int ans=0;int k=0;
        for(int i=0;i<n;i++){
           if(dp[i]>ans){
               ans=dp[i];
               k=i;
           } 
        }
        return check[k];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends