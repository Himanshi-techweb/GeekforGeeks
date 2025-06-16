// User function Template for C++

class Solution {
  public:
    // int numberOfEnclaves(vector<vector<int>> &grid) {
    //     // Code here
        
    // }
    vector<vector<int>> rc={{0, -1}, {-1, 0}, {0, 1}, {1, 0},{0,0}};
    void dfs(int i,int j,int row,int col,vector<vector<int>>&arr){
      arr[i][j]=-1;
      for(int r=0;r<4;r++){
            int nr=i+rc[r][0];
            int nc=j+rc[r][1];
            if(nr>=0 && nr<row && nc>=0 && nc<col && arr[nr][nc]==1){
                dfs(nr,nc,row,col,arr);
            }
      }  
        
    }
    int numberOfEnclaves(vector<vector<int>>& arr) {
        // code here
        int row=arr.size();
        int col=arr[0].size();int cnt=0;
        vector<vector<int>> visit(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            if(arr[i][0]==1)dfs(i,0,row,col,arr);
            if(arr[i][col-1]==1)dfs(i,col-1,row,col,arr);
        }
        for(int i=0;i<col;i++){
            if(arr[0][i]==1)dfs(0,i,row,col,arr);
            if(arr[row-1][i]==1)dfs(row-1,i,row,col,arr);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(arr[i][j]==-1){
                    arr[i][j]=1;
                }
                else if(arr[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};
