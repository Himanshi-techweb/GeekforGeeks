class Solution {
  public:
    // void dfs(int i,int j,int row,int col,vector<vector<int>> &arr,vector<vector<int>>&vis,vector<vector<int>>&ans){
    //   vis[i][j]=1;
    //   for(int k=0;k<4;k++){
    //       int nr=i+rc[k][0];
    //       int nc=j+rc[k][1];
    //       if(nr>=0 &&nr<row && nc>=0 && nc<col &&vis[nr][nc]==0){
               
    //       }
    //   }
    // }
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& arr) {
        // Code here
        int row=arr.size();
        int col=arr[0].size();
        vector<vector<int>> ans(row,vector<int>(col,INT_MAX));
        vector<vector<int>> vis(row,vector<int>(col,0));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> rc={{0,-1},{-1,0},{0,1},{1,0}};
        
        for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
            if(arr[i][j]==1){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
           } 
        }
        while(!q.empty()){
          auto front=q.front();q.pop();
          int r=front.first.first;
          int c=front.first.second;
          int dist=front.second;
          ans[r][c]=min(ans[r][c],dist);
          for(int i=0;i<4;i++){
              int nr=r+rc[i][0];
              int nc=c+rc[i][1];
              if(nr>=0 && nr<row && nc>=0 && nc<col && vis[nr][nc]==0){
                  q.push({{nr,nc},dist+1});
                  vis[nr][nc]=1;
              }
          }
        }
        return ans;
    }
};