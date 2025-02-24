//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public://multisource and manage negative cycle
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        vector<vector<int>> cost(n,vector<int>(n));
        
        for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
              if(mat[i][j]!=-1)cost[i][j]=mat[i][j];
              else {
                  cost[i][j]=INT_MAX;
              }
                  
        }}
        for(int k=0;k<n;k++){
        //   vector<vector<int>> check(n,vector<int>(n));          
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  if(cost[i][k]!=INT_MAX && cost[k][j]!=INT_MAX){
                    int temp=cost[i][k]+cost[k][j];
                  cost[i][j]=min(cost[i][j],temp);  
                  }
              }
          }
        //   cost=check;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j]==INT_MAX){
                    mat[i][j]=-1;
                }
                else{
                    mat[i][j]=cost[i][j];
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends