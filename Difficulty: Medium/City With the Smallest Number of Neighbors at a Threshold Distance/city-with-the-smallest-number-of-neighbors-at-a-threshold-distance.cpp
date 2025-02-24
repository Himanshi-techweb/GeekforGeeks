//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int th) {
        // Your code here
        // int n=mat.size();
        vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
        // vector<vector<int>> mat(n,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
           int x=edges[i][0];
           int y=edges[i][1];
           int w=edges[i][2];
           cost[x][y]=w;
           cost[y][x]=w;
        }
        // for(int i=0;i<n;i++){
        //       for(int j=0;j<n;j++){
        //       if(mat[i][j]!=-1)cost[i][j]=mat[i][j];
        //       else {
        //           cost[i][j]=INT_MAX;
        //       }
                  
        // }}
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
        int min_check=n;
        int k=-1;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=0;j<n;j++){
                if(i!=j && cost[i][j]<=th){
                  x++;  
                }
            }
            if(x<min_check || (x==min_check && i>k)){
                min_check=x;
                k=i;
            }
        }
        
        return k;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends