class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it :edges){
            int x=it[0];int y=it[1];int wt=it[2];
            adj[x].push_back({y,wt});
        }
        queue<int> q;
        vector<int> dis(V,INT_MAX);
        q.push(0);
        dis[0]=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto it:adj[front]){
                if(dis[it.first]>dis[front]+it.second){
                    dis[it.first]=dis[front]+it.second;
                    q.push(it.first);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dis[i]==INT_MAX)dis[i]=-1;
        }
        return dis; 
    }
};
