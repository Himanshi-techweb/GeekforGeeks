// User function Template for C++
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
    // void dfs(int i,vector<vector<int>>&adj,vector<int> &visit,int V){
    //     visit[i]=1;
    //     for(int j=0;j<V;j++){
    //         if(adj[i][j]==1 && visit[j]==0)dfs(j,adj,visit,V);
    //     }
    // }
    // int numProvinces(vector<vector<int>> adj, int V) {
    //     // code here
    //     vector<vector<int>>adj2(V);
    //     vector<int> visit(V,0);int x=0;
    //     for(int i=0;i<V;i++){
    //       if(visit[i]==0){
    //           dfs(i,adj,visit,V);
    //           x++;
    //       } 
    //     }
    //     return x;
    // }
    
    int numProvinces(vector<vector<int>> adj, int V){
       Disjoint check(V);
       int cnt=0;
       //vector<pair<int,int>> edge;
       for(int i=0;i<V;i++){
           for(int j=0;j<V;j++){
                if(i!=j && adj[i][j]==1){
                    if(check.findUParent(i)!=check.findUParent(j)){
                       check.Unionbysize(i,j);
                    } 
                }
           }
       }
       for(int i=0;i<V;i++){
           check.findUParent(i);
       }
       unordered_set<int> q;
       for(auto it:check.parent){
          q.insert(it); 
       }
       return q.size()-1;
    }
};