// User function Template for C++
class Solution {
  public:
   
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edge) {
        // code here
        vector<vector<pair<int,int>>> arr(V);
        vector<int> dist(V,INT_MAX);
        queue<int> q;
        q.push(0);
        for(auto it:edge){
            int x=it[0];
            int y=it[1];
            int w=it[2];
            arr[x].push_back({y,w});
        }
        dist[0]=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto it:arr[front]){
                int adjnode=it.first;
                int wt=it.second;
                if(dist[adjnode]>wt+dist[front]){
                    dist[adjnode]=wt+dist[front];
                    q.push(adjnode);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }
        return dist;
    }
};
