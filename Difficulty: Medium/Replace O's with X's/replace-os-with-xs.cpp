// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rc={{0, -1}, {-1, 0}, {0, 1}, {1, 0},{0,0}};
    void dfs(int i,int j,int row,int col,vector<vector<char>>&arr){
      arr[i][j]='*';
      for(int r=0;r<4;r++){
            int nr=i+rc[r][0];
            int nc=j+rc[r][1];
            if(nr>=0 && nr<row && nc>=0 && nc<col && arr[nr][nc]=='O'){
                dfs(nr,nc,row,col,arr);
            }
      }  
        
    }
    vector<vector<char>> fill(vector<vector<char>>& arr) {
        // code here
        int row=arr.size();
        int col=arr[0].size();
        vector<vector<int>> visit(row,vector<int>(col,0));
        vector<vector<char>> copy=arr;
        for(int i=0;i<row;i++){
            if(arr[i][0]=='O')dfs(i,0,row,col,arr);
            if(arr[i][col-1]=='O')dfs(i,col-1,row,col,arr);
        }
        for(int i=0;i<col;i++){
            if(arr[0][i]=='O')dfs(0,i,row,col,arr);
            if(arr[row-1][i]=='O')dfs(row-1,i,row,col,arr);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(arr[i][j]=='*'){
                    arr[i][j]='O';
                }
                else if(arr[i][j]=='O')arr[i][j]='X';
            }
        }
        return arr;
    }
};