class Solution {
  public:
    vector<vector<int>> adj;
    bool dfs(vector<bool> & visit,vector<bool> &pathvisit,int i){
        visit[i]=true;
        pathvisit[i]=true;
        for(auto it:adj[i]){
            if(!visit[it]){
              
                if(dfs(visit,pathvisit,it))return true;
            }
            else if(pathvisit[it])return true;
        }
        pathvisit[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        adj.resize(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<bool> visit(V,false);
        vector<bool> pathvisit(V,false);
        for(int i=0;i<V;i++){
            if(!visit[i] && dfs(visit,pathvisit,i))return true;
        }
        return false;
    }
};