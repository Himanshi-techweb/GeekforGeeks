class Solution {
  public:
    vector<vector<int>> rc={{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{1,-2},{-1,-2},{2,1}};
    void solve(int st_i,int st_j,int t_i,int t_j, vector<vector<int>> &mini,int n){
       if(st_i==t_i && st_j==t_j){
           return;
       } 
       for(auto it:rc){
           int nr=it[0]+st_i;int nc=it[1]+st_j;
           if(nr>=0 && nr< n && nc>=0 && nc<n ){
               if(1+mini[st_i][st_j]<mini[nr][nc]){
                  mini[nr][nc]=1+mini[st_i][st_j]; 
                  solve(nr,nc,t_i,t_j,mini,n);
               }
           }
       }
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        
        vector<vector<int>> mini(n,vector<int> (n,INT_MAX));
        int st_i=knightPos[0]-1;int st_j=knightPos[1]-1;
        int t_i=targetPos[0]-1;int t_j=targetPos[1]-1;
        mini[st_i][st_j]=0;
        queue<pair<int,int>> q;
        q.push({st_i,st_j});
        while(!q.empty()){
            auto front=q.front();q.pop();
            int i=front.first;int j=front.second;
            if(i==t_i && j==t_j)return mini[i][j];
            for(auto it:rc){
                int nr=it[0]+i;int nc=it[1]+j;
                if(nr>=0 && nr< n && nc>=0 && nc<n ){
                    if(1+mini[i][j]<mini[nr][nc]){
                        mini[nr][nc]=1+mini[i][j];
                        q.push({nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};