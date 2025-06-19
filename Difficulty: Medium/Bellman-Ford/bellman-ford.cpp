// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edge, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            for(int j=0;j<edge.size();j++){
               if(dist[edge[j][0]]!=1e8 && dist[edge[j][0]]+edge[j][2]<dist[edge[j][1]]){
                   dist[edge[j][1]]=dist[edge[j][0]]+edge[j][2];
               } 
            }
        }
       // vector<int> distance=dist;
        for(int i=0;i<1;i++){
           for(int j=0;j<edge.size();j++){
               if(dist[edge[j][0]]!=1e8 && dist[edge[j][0]]+edge[j][2]<dist[edge[j][1]]){
                   return {-1};
               } 
            } 
        }
        return dist;
    }
};
