//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int maximumPath(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int m=matrix[0].size();
      vector<int> next=matrix[n-1];
      
      for(int i=n-2;i>=0;i--){
        vector<int> curr(m);
        for(int j=0;j<m;j++){
        int left=(j>0)?next[j-1]:INT_MIN;
        int below=next[j];
        int right=(j<m-1)?next[j+1]:INT_MIN;
        curr[j]=matrix[i][j]+max(left,max(below,right));
        }
        next=curr;
      }
      return *max_element(next.begin(),next.end());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.maximumPath(mat) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends