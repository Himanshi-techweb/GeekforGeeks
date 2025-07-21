class Solution {
  public:
    //bool condition=false;bool condition2=false;
    
    bool isCycle(int V, vector<vector<int>>& edge) {
        // Code here
       vector<vector<int>> adj(V);
       for(auto it:edge){
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
       }
       queue<int> q;//node,parent
       vector<int> visit(V,0);
       vector<int> parent(V,INT_MIN);
       
       for(int i=0;i<V;i++){
           if(!visit[i]){
               q.push(i);
               visit[i]=1;
               parent[i]=-1;
               while(!q.empty()){
                   int front=q.front();
                   q.pop();
                   for(auto it:adj[front]){
                       if(!visit[it]){
                           parent[it]=front;
                           q.push(it);
                           visit[it]=1;
                       }
                       else if(visit[it] && parent[it]!=-1 && parent[it]!=INT_MIN && it!=parent[front]){
                           return true;
                       }
                   }
               }
           }
       }
       return false;
       
    }
};