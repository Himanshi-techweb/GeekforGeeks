// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        if(grid[destination.first][destination.second]==0)return -1;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push(source);
        dist[source.first][source.second]=0;
        vector<pair<int,int>> rc={{0,-1},{-1,0},{0,1},{1,0}};
        while(!q.empty()){
          int row=q.top().first;
          int col=q.top().second;
          q.pop();
          for(int i=0;i<rc.size();i++){
              int r=row+rc[i].first;
              int c=col+rc[i].second;
              if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && dist[r][c]>dist[row][col]+1){
                  dist[r][c]=1+dist[row][col];
                  q.push({r,c});
              }
          }
        }
        if(dist[destination.first][destination.second]==INT_MAX)return -1;
        return dist[destination.first][destination.second];
    }
};
