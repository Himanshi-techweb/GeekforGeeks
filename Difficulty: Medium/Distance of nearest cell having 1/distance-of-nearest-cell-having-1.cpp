class Solution {
  public:
    int m,n;
    vector<vector<int>> rc={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        m=grid.size();n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        // queue<pair<int,int>> q;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+rc[i][0];int nc=c+rc[i][1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0){
                    if(dist[nr][nc]>dist[r][c]+1){
                        dist[nr][nc]=dist[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return dist;
    }
};