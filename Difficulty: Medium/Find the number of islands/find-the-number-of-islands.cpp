class Solution {
  public:
    int x=0;
    vector<int> h={-1,0,1};int i1=0;
    vector<int> c={-1,0,1};int j1=0;
    void dfs(int i,int j,int m,int n,vector<vector<char>> &grid,vector<vector<int>> &visit){
        visit[i][j]=1;
        for(int q=0;q<3;q++){
            for(int r=0;r<3;r++){
                i1=i+h[q];
                j1=j+c[r];
                if(i1>=0 && i1<m && j1>=0 && j1<n){
                    if(visit[i1][j1]==0 && grid[i1][j1]=='L'){
                        dfs(i1,j1,m,n,grid,visit);
                    }
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        int x=0;
        vector<vector<int>> visit(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visit[i][j]==0 && grid[i][j]=='L'){
                    dfs(i,j,m,n,grid,visit);
                    x++;
                }
                
            }
        }
        return x;
    }
};