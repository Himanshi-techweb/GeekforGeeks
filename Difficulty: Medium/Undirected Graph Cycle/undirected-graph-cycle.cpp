class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>> q;
        vector<bool>visit(V,false);
        for(int i=0;i<V;i++){
            if(!visit[i]){
                visit[i]=true;
                q.push({i,-1});
                while(!q.empty()){
                    auto front =q.front();
                    int node=front.first;
                    int actual=front.second;
                    q.pop();
                    for(auto it:adj[node]){
                        if(!visit[it]){
                            q.push({it,node});
                            visit[it]=true;
                        }
                        else if(it!=actual)return true;
                    }
                }
            }
        }
        return false;
    }
};