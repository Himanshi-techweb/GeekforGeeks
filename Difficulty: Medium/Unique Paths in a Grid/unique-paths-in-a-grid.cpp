class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        //code here
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> rc={{0,1},{1,0}};
        if(grid[0][0]==1 || grid[m-1][n-1]==1)return 0;
        q.push({0,0});
        vector<int> way(m*n+1);
        way[0]=1;
        // visit[0][0]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int node=row*n + col;
            for(auto it:rc){
                int nr=row+it[0];int nc=col+it[1];
                if(nr<m && nc<n && grid[nr][nc]==0 ){
                    
                    int adjnode=nr*n +nc;
                    if(way[adjnode]==0)q.push({nr,nc});
                    way[adjnode]=way[adjnode]+way[node];
        
                }
            }
        }
        return way[m*n -1];
        
    }
    

};