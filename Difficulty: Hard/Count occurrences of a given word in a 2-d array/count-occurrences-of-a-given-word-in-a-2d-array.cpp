// User function Template for C++

class Solution {
  public:
    int findOccurrence(vector<vector<char> > &mat, string target) {
        // vector<vector<int>> rc={{-1,0},{0,-1},{0,1},{1,0}};
        int cnt=0;
        vector<vector<int>> rc={{-1,0},{0,-1},{0,1},{1,0}};
        int m=mat.size();int n=mat[0].size();
        using State = tuple<int, int, int, vector<vector<bool>>>;  // define the tuple type
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(mat[i][j]==target[0]){
                queue<State> q;
                vector<vector<bool>> vis(m,vector<bool>(n,false));
                vis[i][j]=true;
                q.push(State{i,j,1,vis});
                while(!q.empty()){
                    auto state = q.front();
                    int row = get<0>(state);
                    int col = get<1>(state);
                    int index = get<2>(state);
                    vector<vector<bool>> path_vis = get<3>(state);
                    q.pop();
                    if(index==target.size()){
                        cnt++;continue;
                    }
                    for(auto it:rc){
                      int nr=row+it[0] ;int nc=col+it[1];
                      if(nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc]==target[index] && !path_vis[nr][nc]){
                        auto new_vis=path_vis;
                        new_vis[nr][nc]=true;
                        q.push(State{nr,nc,index+1,new_vis});
                      }
                    }
                }
               }
            }
        }
        return cnt;
    }
};