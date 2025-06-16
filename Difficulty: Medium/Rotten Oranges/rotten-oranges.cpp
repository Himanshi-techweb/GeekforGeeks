class Solution {
  public:
    int orangesRotting(vector<vector<int>>& arr) {
        // Code here
        int row=arr.size();
        int col=arr[0].size();
        //vector<vector<int>> rotten;
        int nrotten=0;int cnt=0;
        int fresh=0;
        queue<pair<int,int>> st;
        for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(arr[i][j]==2){
                   st.push({i,j});
                   nrotten++;
               }
               if(arr[i][j]==1)fresh++;
           } 
        }
        if(fresh==0)return 0;
        vector<vector<int>> rc={{-1,0},{0,1},{0,-1},{1,0}};
        while(!st.empty() && fresh>0){
          int size=st.size();
          cnt++;
          for(int i=0;i<size;i++){
            pair<int,int> front=st.front();
            st.pop();
            for(int i=0;i<4;i++){
               int nr=front.first+rc[i][0];
               int nc=front.second+rc[i][1];
               if(nr>=0 && nr<row && nc>=0 && nc<col &&arr[nr][nc]==1){
                   st.push({nr,nc});
                   arr[nr][nc]=2;
                   fresh--;
               }
            }  
          }
        }
        if(fresh) return -1;
        return cnt;
    }
};