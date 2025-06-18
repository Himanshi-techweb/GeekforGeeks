
class Solution {
  public:
    int MinimumEffort(int row, int col, vector<vector<int>> &height) {
        // code here
        vector<vector<int>> dist(row,vector<int>(col,INT_MAX));
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>q;
        q.push({0,{0,0}});
        dist[0][0]=0;
        vector<pair<int,int>> rc={{0,-1},{-1,0},{0,1},{1,0}};
        while(!q.empty()){
            int wt=q.top().first;
            int r=q.top().second[0];
            int c=q.top().second[1];
            q.pop();
            for(int i=0;i<rc.size();i++){
                int nr=r+rc[i].first;
                int nc=c+rc[i].second;
                if(nr>=0 && nr<row && nc>=0 && nc<col){
                    int diff=abs(height[r][c]-height[nr][nc]);
                    diff=max(wt,diff);
                    if(dist[nr][nc]>diff){
                        dist[nr][nc]=diff;
                        q.push({diff,{nr,nc}});
                    }
                }
            }
        }
        return dist[row-1][col-1];
    }
};
