class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edge) {
        // Code here
        vector<vector<int>> arr(V);
        queue<int> q;
        vector<int> color(V,-1);
        for(int i=0;i<edge.size();i++){
           arr[edge[i][0]].push_back(edge[i][1]);
           arr[edge[i][1]].push_back(edge[i][0]);
        }
        q.push(0);
        color[0]=0;
        while(!q.empty()){
           int front=q.front();
           q.pop();
           for(auto it:arr[front]){
               if(color[it]==-1){
                  color[it]=(color[front]==0?1:0); 
                  q.push(it);
               }
               else if(color[it]==color[front]){
                return false;   
               }
           }
        }
        return true;
    }
};