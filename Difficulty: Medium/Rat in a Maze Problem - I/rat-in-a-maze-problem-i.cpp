class Solution {
  public:
    vector<string> ans;
    vector<pair<pair<int,int>,char>> rc={{{0,-1},'L'},{{-1,0},'U'},{{0,1},'R'},{{1,0},'D'}};
    void solve(int i,int j,vector<vector<int>> &arr,vector<vector<int>> &visit,int m,int n,string &curr){
        if(i==m-1 && j==n-1){
            ans.push_back(curr);
            return;
        }
        for(auto it:rc){
            int nr=it.first.first+i;int nc=it.first.second+j;
            if(nr>=0 && nr<m && nc>=0 && nc<n && !visit[nr][nc] && arr[nr][nc]==1){
                visit[nr][nc]=1;
                curr=curr+it.second;
                solve(nr,nc,arr,visit,m,n,curr);
                curr.pop_back();
                visit[nr][nc]=0;
            }
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
    // Write your code here.
       int m=maze.size();int n=maze[0].size();
       if(maze[0][0]==0 || maze[m-1][n-1]==0)return {};
       
       string curr="";
       vector<vector<int>> visit(m,vector<int> (n,0));
       visit[0][0]=1;
       solve(0,0,maze,visit,m,n,curr);
       sort(ans.begin(),ans.end());
       return ans;
    }
};
