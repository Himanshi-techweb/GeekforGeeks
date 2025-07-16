class Solution {
  public:
    vector<pair<pair<int,int>,int>> rc={{{-1,0},'U'},{{1,0},'D'},{{0,-1},'L'},{{0,1},'R'}};
    vector<string> ans;
    void solve(int i,int j,vector<vector<int>> &arr,string &x,int n,vector<vector<int>> &visit){
    if(i==n-1 && j==n-1){
        ans.push_back(x);return;
    }
    if(i>=n || j>=n)return;
    for(auto it:rc){
        int nr=i+it.first.first;int nc=j+it.first.second;
        if(nr>=0 && nr<n && nc>=0 && nc<n &&arr[nr][nc]==1 && !visit[nr][nc]){
           x+=it.second;
           visit[nr][nc]=1;
           solve(nr,nc,arr,x,n,visit);
           x.pop_back();
           visit[nr][nc]=0;
        }
    }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
    // Write your code here.
    string x="";
    int n=maze.size();
    vector<vector<int>> visit(n,vector<int> (n,0));
    if(maze[0][0]=='0' || maze[n-1][n-1]=='0')return {};
    visit[0][0]=1;
    solve(0,0,maze,x,n,visit);
    sort(ans.begin(),ans.end());
    return ans;
    }
};
