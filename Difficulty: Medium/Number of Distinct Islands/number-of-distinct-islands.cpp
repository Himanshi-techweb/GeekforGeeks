// User function Template for C++
class Solution {
  public:
    vector<vector<int>> rc={{0,-1},{-1,0},{0,1},{1,0}};
    void dfs(int i,int j,int i_base,int j_base,int m,int n,vector<vector<int>>& arr,vector<vector<int>> &visit,vector<pair<int,int>> &check){
        visit[i][j]=1;
        int ni=i-i_base;
        int nj=j-j_base;
        check.push_back({ni,nj});
        for(auto it:rc){
            int nr=i+it[0];
            int nc=j+it[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !visit[nr][nc] && arr[nr][nc]==1){
                visit[nr][nc]=1;
                dfs(nr,nc,i_base,j_base,m,n,arr,visit,check);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& arr) {
        // code here
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>> visit(m,vector<int> (n,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visit[i][j] && arr[i][j]==1){
                    vector<pair<int,int>> check;
                    dfs(i,j,i,j,m,n,arr,visit,check);
                    sort(check.begin(),check.end());
                    st.insert(check);
                }
            }
        }
        return st.size();
    }
};
