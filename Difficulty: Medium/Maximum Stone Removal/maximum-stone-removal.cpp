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
    int maxRemove(vector<vector<int>>& arr, int n) {
        // Code here
        int maxrow=0;
        int maxcol=0;
        for(auto it:arr){
           maxrow=max(maxrow,it[0]);
           maxcol=max(maxcol,it[1]);
        }
        Disjoint check(maxrow+maxcol+1);
        unordered_map<int,int> node;
        for(int i=0;i<arr.size();i++){
            int row=arr[i][0];
            int col=arr[i][1];
            check.Unionbysize(row,col+maxrow+1);
            node[row]=1;
            node[col+maxrow+1]=1;
        }
        int cnt=0;
        for(auto it:node){
            if(check.findUParent(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};