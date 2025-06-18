class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edge) {
        // Code here
        
        vector<vector<pair<int,int>>> arr(n+1);
        for(int i=0;i<m;i++){
            arr[edge[i][0]].push_back({edge[i][1],edge[i][2]});
            arr[edge[i][1]].push_back({edge[i][0],edge[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dist(n+1,INT_MAX);
        dist[1]=0;
        q.push({0,1});
        vector<int> parent(n+1,-1);
        //parent[1]=-1;
        while(!q.empty()){
           int wt=q.top().first;
           int node=q.top().second;
           q.pop();
           for(auto it:arr[node]){
               int x=it.first;
               int y=it.second;
               if(dist[x]>y+wt){
                   q.push({y+wt,x});
                   dist[x]=y+wt;
                   parent[x]=node;
               }
           }
        }
        if(dist[n]==INT_MAX )return {-1};
        vector<int> result;
        int node=n;
        while(node!=-1){
            result.push_back(node);
            node=parent[node];
        }
        result.push_back(dist[n]);
        reverse(result.begin(),result.end());
        if(result.back()!=n )return {-1};
        return result;
    }
};