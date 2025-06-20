class Solution {
  public:
    //bool condition=false;bool condition2=false;
    bool dfs(int src,int parent,vector<vector<int>>&adj,vector<int> &visit){
       visit[src]=1;
       for(auto it:adj[src]){
           if(visit[it]!=1 && it!=parent){
              if(dfs(it,src,adj,visit))return true; 
           }
           else if(visit[it]==1 && it!=parent){
               return true;
           }
       }
       return false;
    }
    bool isCycle(int V, vector<vector<int>>& edge) {
        // Code here
       vector<vector<int>> adj(V);
       for(auto it:edge){
           adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
       }
       vector<int> visit(V,0);
       for(int i=0;i<V;i++){
           if(!visit[i]){
               if(dfs(i,-1,adj,visit)) return true;
           }
       }
       return false;
    }
};