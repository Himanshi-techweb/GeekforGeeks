class Solution {
  public:
    unordered_set<string>st ;
    vector<vector<int>> rc={{-1,0},{0,-1},{0,1},{1,0}};
    int m,n;
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        m=grid.size();n=grid[0].size();
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visit[i][j] && grid[i][j]=='L'){
                    q.push({i,j});
                    string str="";
                    str+=to_string(i-i);
                    str+="+";
                    str+=to_string(j-j);
                    str+="+";
                    while(!q.empty()){
                        auto r=q.front().first;
                        auto c=q.front().second;
                        visit[r][c]=true;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=r+rc[k][0];int nc=c+rc[k][1];
                            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='L' && !visit[nr][nc]){
                                q.push({nr,nc});
                                nr=nr-i;
                                nc=nc-j;
                                str+=to_string(nr);
                                str+="+";
                                str+=to_string(nc);
                                str+="+";
                            }
                        }
                    }
                    st.insert(str);
                }
            }
        }
        
        return st.size();
        
    }
};
