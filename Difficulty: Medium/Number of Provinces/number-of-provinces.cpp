// User function Template for C++

class Solution {
  public:
    void dfs(int i,vector<vector<int>>&adj2,vector<int> &visit){
        visit[i]=1;
        for(auto it:adj2[i]){
            if(visit[it]==0)dfs(it,adj2,visit);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>adj2(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    adj2[i].push_back(j);
                    adj2[j].push_back(i);
                }
            }
        }
        vector<int> visit(V,0);int x=0;
        for(int i=0;i<V;i++){
           if(visit[i]==0){
               dfs(i,adj2,visit);
               x++;
           } 
        }
        return x;
    }
};