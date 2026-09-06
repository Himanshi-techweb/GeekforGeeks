class DSU {
    public:
    vector<int> parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int findparent(int node){
        if(node==parent[node])return node;
        return parent[node]=findparent(parent[node]);
    }
    void unite(int x,int y){
        int px=findparent(x);
        int py=findparent(y);
        if(px==py)return;
        if(rank[px]>rank[py])parent[py]=px;
        else if(rank[px]<rank[py])parent[px]=py;
        else {
            parent[py]=px;
            rank[px]++;
        }
    }
};
class Solution {
  public:
    vector<vector<int>> rc={{0,-1},{-1,0},{0,1},{1,0}};
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        //r*col + c;
        int total=(n*m +m)+1;
        DSU dsu(total);
        vector<int> ans;
        int cnt=0;
        vector<vector<int>>visit(n,vector<int>(m,0));
        for(int i=0;i<operators.size();i++){
            int r=operators[i][0];int c=operators[i][1];
            if(visit[r][c]==1)ans.push_back(cnt);
            else{
                visit[r][c]=1;
                cnt++;
                for(auto it:rc){
                    int nr=r+it[0];int nc=c+it[1];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && visit[nr][nc]){
                        int node=r*m +c;
                        int newnode=nr*m +nc;
                        int pnode=dsu.findparent(node);
                        int pnewnode=dsu.findparent(newnode);
                        //same parent
                        if(pnode==pnewnode){
                            continue;
                        }
                        //not same parent
                        else{
                            cnt--;
                            dsu.unite(node,newnode);
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
        return ans;
    }
};