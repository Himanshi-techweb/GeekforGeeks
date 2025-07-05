class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flight, int src, int dst, int k) {
        // Code here
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flight){
            int u=it[0];int v=it[1];int price=it[2];
            adj[u].push_back({v,price});
        }
        queue<pair<int,pair<int,int>>> q;//(stop,(price,node))
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{0,src}});
        while(!q.empty()){
            int stop=q.front().first;
            int price=q.front().second.first;
            int node=q.front().second.second;
            q.pop();
            if(stop>k+1)continue;
            for(auto it:adj[node]){
              if(dist[it.first]>price+it.second && stop<=k){
                  dist[it.first]=price+it.second;
                  q.push({stop+1,{dist[it.first],it.first}});
              }  
            }
        }
        return (dist[dst]!=INT_MAX)?dist[dst]:-1;
    }
};