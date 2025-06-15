class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        queue<int> q;
        int x=adj.size();
        if(x==0)return {};
        vector<int> visit(x+1,0);
        q.push(0);
        visit[0]=1;
        vector<int> arr;
        while(!q.empty()){
           int size=q.size();
           for(int i=0;i<size;i++){
              int front=q.front();q.pop();
              arr.push_back(front);
              for(auto i:adj[front]){
               if(visit[i]==0){
                   visit[i]++;
                   q.push(i);
               }
              }
           }
        }
        return arr;
    }
};