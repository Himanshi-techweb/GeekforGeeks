//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> arr[]) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> > q;
        vector<int> vis(V,0);

        //in this not create MST vector as it is asking for only weight if tee also aske then store 
        //node and it parent after once it visit so that when it to show tree remove all unnecessary edge
        q.push({0,0,-1});
        int sum=0;
        while(!q.empty()){
            vector<int> temp=q.top();
            int wt=temp[0];
            int node=temp[1];
            int parent=temp[2];
            q.pop();
            if(!vis[node]){
              if(parent==-1){
                vis[node]=1;
              }
              else{
                vis[node]=1;
                sum+=wt;
                //mst.push_back({node,parent});
              }
              for(auto it:arr[node]){
                if(!vis[it[0]]){
                  q.push({it[1],it[0],node});  
                }
              }   
            }
        } return sum; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends