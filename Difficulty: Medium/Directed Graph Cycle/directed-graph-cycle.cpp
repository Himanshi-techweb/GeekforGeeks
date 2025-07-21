class Solution {
  public:
    bool dfs(int i,vector<int> &visit,vector<int> &pathvisit,vector<vector<int>> &adj){
       visit[i]=1;pathvisit[i]=1;
       for(auto it:adj[i]){
           if(!visit[it]){
               if(dfs(it,visit,pathvisit,adj))return true;
           }
           else if(visit[it] &&pathvisit[it])return true;
       }
       pathvisit[i]=0;
       return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edge) {
        vector<vector<int>> adj(V);
        for(auto it:edge){
           adj[it[0]].push_back(it[1]);
        }
        vector<int> visit(V,0);
        vector<int> pathvisit(V,0);
        for(int i=0;i<V;i++){
            if(!visit[i]){
                if(dfs(i,visit,pathvisit,adj))return true;
            }
        }
        return false;
    }
};






























