// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edge, int distanceThreshold) {
        // Your code here
        vector<vector<int>> cnt(n,vector<int> (n,0));
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        for(int i=0;i<n;i++){
            int src=i;
            //apply dijkstra for each src node 
            vector<int> dist(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
            q.push({0,src});
            dist[src]=0;
            while(!q.empty()){
                int node=q.top().second;
                int wt=q.top().first;
                q.pop();
                for(auto it:adj[node]){
                    int adjnode=it.first;
                    int adjwt=it.second;
                    if(dist[adjnode]>dist[node]+adjwt){
                        dist[adjnode]=dist[node]+adjwt;
                        q.push({dist[node]+wt,adjnode});
                    }
                }
                
            }
            for(int i=0;i<n;i++){
                if(dist[i]<=distanceThreshold){
                    cnt[src][i]++;
                }
            }
        }
        vector<int> total(n,0);
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
               sum+=cnt[i][j]; 
            }
            total[i]=sum;
        }
        // sort(total.begin(),total.end());
        // int ans=0;
        int ans=INT_MAX;int ix=0;
        for(int i=0;i<n;i++){
           if(total[i]<ans){
               ans=total[i];
               ix=i;
           }
           else if(total[i]==ans)ix=i;
        }
        return ix;
    }
};
