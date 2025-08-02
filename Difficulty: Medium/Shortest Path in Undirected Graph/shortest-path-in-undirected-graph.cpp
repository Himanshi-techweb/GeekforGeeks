class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V=adj.size();
        queue<int> q;
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto it:adj[front]){
                if(dist[it]>dist[front]+1){
                    dist[it]=dist[front]+1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }
        return dist;
    }
};