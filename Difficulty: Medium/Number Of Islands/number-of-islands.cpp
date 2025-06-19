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
    bool valid(int r,int c,int row,int col){
        return r>=0 && r<row && c>=0 && c<col;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &arr) {
        // code here
        Disjoint check(n*m);
        vector<vector<int>> visit(n,vector<int>(m,0));
        vector<int> ans;int cnt=0;
        vector<vector<int>> rc={{-1,0},{0,-1},{1,0},{0,1}};
        for(int i=0;i<arr.size();i++){
            int row=arr[i][0];
            int col=arr[i][1];
            if(visit[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            visit[row][col]=1;
            cnt++;
            for(auto it:rc){
                int adjrow=it[0]+row;
                int adjcol=it[1]+col;
                if(valid(adjrow,adjcol,n,m)){
                    if(visit[adjrow][adjcol]==1){
                        if(check.findUParent(row*m+ col)!=check.findUParent(adjrow*m+adjcol)){
                           cnt--;
                           check.Unionbysize(row*m+ col,adjrow*m+adjcol);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
