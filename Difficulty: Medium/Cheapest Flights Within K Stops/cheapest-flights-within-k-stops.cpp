class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flight, int src, int dst, int k) {
        // Code here
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});//stop,node,distance
        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>> arr(n);
        for(int i=0;i<flight.size();i++){
            arr[flight[i][0]].push_back({flight[i][1],flight[i][2]});
        }
        dist[src]=0;
        while(!q.empty()){
            int stop=q.front().first;
            int node=q.front().second.first;
            int price=q.front().second.second;
            q.pop();
            if(stop>k)continue;
            for(auto it:arr[node]){
                int adjprice=it.second;
                int adjnode=it.first;
                 if((dist[adjnode]>adjprice+price && adjnode==dst && stop<=k ) || (dist[adjnode]>adjprice+price && stop+1<=k && adjnode!=dst)){
                   dist[adjnode]=adjprice+price; 
                   q.push({stop+1,{adjnode,adjprice+price}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
        
    }
};