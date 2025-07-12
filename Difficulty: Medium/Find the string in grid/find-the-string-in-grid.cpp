class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> mat, string target) {
        // Code here
        vector<vector<int>> rc={{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
        int m=mat.size();int n=mat[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(mat[i][j]==target[0]){
                 for(auto it:rc){
                     bool valid=true;
                     int row=i;int col=j;
                     for(int k=1;k<target.size();k++){
                         row=row+it[0];col=col+it[1];
                         if(row<0 || row>=m || col<0 || col>=n || mat[row][col]!=target[k]){
                             valid=false;
                             break;
                         }
                     }
                     if(valid){
                         ans.push_back({i,j});
                         break;
                     }
                 }
               }
            }
        }
        return ans;
    }
};