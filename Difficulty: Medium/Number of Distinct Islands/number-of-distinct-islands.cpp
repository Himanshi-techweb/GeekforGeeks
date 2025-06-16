// User function Template for C++
#include <set>
class Solution {
  public:
    vector<vector<int>> rc={{0,-1},{-1,0},{0,1},{1,0}};
    void dfs(int i,int j,int i_base,int j_base,int row,int col,vector<vector<int>>&visit,vector<vector<int>>&arr,vector<pair<int,int>>&check){
        check.push_back({i-i_base,j-j_base});
        visit[i][j]=1;
        for(int k=0;k<rc.size();k++){
            int nr=i+rc[k][0];
            int nc=j+rc[k][1];
            if(nr>=0 && nr<row && nc>=0 && nc<col && arr[nr][nc]==1 && !visit[nr][nc]){
                dfs(nr,nc,i_base,j_base,row,col,visit,arr,check);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& arr) {
        // code here
        set<vector<pair<int,int>>> st;
        int row=arr.size();
        int col=arr[0].size();
        vector<vector<int>> visit(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(arr[i][j]==1 && !visit[i][j]){
                    vector<pair<int,int>> check;
                    dfs(i,j,i,j,row,col,visit,arr,check);
                    st.insert(check);
                }
            }
        }
        return st.size();
    }
};
