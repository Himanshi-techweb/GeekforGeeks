class Disjoint{
  public:
  vector<int> size,parent;
  Disjoint(int n){
      size.resize(n+1,1);
      parent.resize(n+1);
      for(int i=0;i<=n;i++){
          parent[i]=i;
      }
  }
  int findUParent(int node){
      if(node==parent[node])return node;
      return parent[node]=findUParent(parent[node]);
  }
  void Unionbysize(int u,int v){
      int ulp_u=findUParent(u);
      int ulp_v=findUParent(v);
      if(ulp_u==ulp_v)return;
      if(size[ulp_u]<size[ulp_v]){
          parent[ulp_u]=ulp_v;
          size[ulp_v]+=size[ulp_u];
      }
      else{
          parent[ulp_v]=ulp_u;
          size[ulp_u]+=size[ulp_v];
      }
  }
};
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<pair<int,pair<int,int>>> edge;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjnode=it[0];
                int wt=it[1];
                edge.push_back({wt,{i,adjnode}});
            }
        }
        sort(edge.begin(),edge.end());
        int mstsum=0;
        Disjoint check(V);
        for(int i=0;i<edge.size();i++){
            int u=edge[i].second.first;
            int v=edge[i].second.second;
            if(check.findUParent(u)!=check.findUParent(v)){
              mstsum+=edge[i].first;
              check.Unionbysize(u,v);
            }
        }
        return mstsum;
    }
};