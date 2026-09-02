class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src){
        vector<int> dis(V+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        dis[src] = 0;
        q.push({0, src});
        while(!q.empty()){
            auto [d, u] = q.top(); q.pop();
            if(d > dis[u]) continue;
            for(auto [v, w] : adj[u]){
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
        return dis;
    }

    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<pair<int,int>>> adj(V+1);
        for(auto &it : edges){
            int x=it[0], y=it[1], wt=it[2];
            adj[x].push_back({y, wt});
            adj[y].push_back({x, wt});
        }

        vector<int> distSrc  = dijkstra(V, adj, src);
        vector<int> distDest = dijkstra(V, adj, dest);

        int total = distSrc[dest];
        if(total == INT_MAX) return {-1};

        vector<int> ans;
        int cur = src;
        ans.push_back(cur);
        while(cur != dest){
            int next = -1;
            for(auto [v, w] : adj[cur]){
                if(v == cur) continue; // skip self-loops
                if(distSrc[cur] + w + distDest[v] == total){
                    if(next == -1 || v < next) next = v;
                }
            }
            ans.push_back(next);
            cur = next;
        }
        return ans;
    }
};