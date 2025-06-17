class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V=adj.size();
        vector<vector<int>> arr(V);
        
        vector<int> dist(V,INT_MAX);
        queue<int> q;
        dist[src]=0;
           q.push(src);
           while(!q.empty()){
            int front=q.front();
            q.pop();
            if(dist[front]!=INT_MAX){
                for(auto it:adj[front]){
                    // dist[it]=min(dist[it],dist[front]+1);
                    if(dist[it]>dist[front]+1){
                      dist[it]=dist[front]+1;
                      q.push(it);  
                    }
                }
            }
           }
        for(auto &it:dist){
            if(it==INT_MAX)it=-1;
        }
        return dist;
    }
};