// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& road) {
        // code here
        vector<vector<pair<int,int>>> arr(n);
        for(auto it:road){
          arr[it[0]].push_back({it[1],it[2]});
          arr[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        q.push({0,0});
        vector<int> dist(n,INT_MAX);
        vector<long long> way(n,0);
        dist[0]=0;
        way[0]=1;
        const int MOD=1e9 + 7;
        while(!q.empty()){
            int distance=q.top().first;
            int node=q.top().second;
            q.pop();
            if(dist[node]<distance)continue;
            for(auto it:arr[node]){
                int adjnode=it.first;
                int adjdist=it.second;
                if(dist[adjnode]>distance+adjdist){
                  way[adjnode]=way[node];
                  q.push({distance+adjdist,adjnode});
                  dist[adjnode]=distance+adjdist;
                }
                else if(dist[adjnode]==distance+adjdist){
                    way[adjnode]=(way[adjnode]+way[node]) %MOD;
                }
            }
        }
        return way[n-1];
    }
};