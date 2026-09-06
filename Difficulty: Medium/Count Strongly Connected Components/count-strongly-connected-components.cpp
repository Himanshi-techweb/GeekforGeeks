class Solution {
  public:
    stack<int> q;
    void dfs(int i,vector<vector<int>> &adj,vector<int> &visit){
    //   q.push(i);
       visit[i]=1;
       for(auto it:adj[i]){
           if(!visit[it])dfs(it,adj,visit);
       }
       q.push(i);
    }
    void dfs1(int i,vector<vector<int>> &adj,vector<int> &visit){
       
       visit[i]=1;
       for(auto it:adj[i]){
           if(!visit[it])dfs(it,adj,visit);
       }
    }
    int countSCC(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<vector<int>> revadj(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            revadj[it[1]].push_back(it[0]);
        }
        vector<int> visit(V,0);
        for(int i=0;i<V;i++){
            if(!visit[i])dfs(i,adj,visit);
        }
        vector<int> newvisit(V,0);
        int cnt=0;
        while(!q.empty()){
            auto front=q.top();
            q.pop();
            if(!newvisit[front]){
                dfs1(front,revadj,newvisit);
                cnt++;
            }
            
        }
        return cnt;
        
    }
};