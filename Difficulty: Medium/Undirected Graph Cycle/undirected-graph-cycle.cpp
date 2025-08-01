class Solution {
  public:
    //bool condition=false;bool condition2=false;
    
    bool isCycle(int V, vector<vector<int>>& edge) {
        // Code here
       vector<vector<int>> adj(V+1);
       for(auto it:edge){
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
       }
       vector<int> visit(V+1);
       for(int i=0;i<=V;i++){
           queue<pair<int,int>> q;
        q.push({i,-1});//node,parent
           if(!visit[i]){
            visit[i]=1;
            while(!q.empty()){
           int node=q.front().first;int parent=q.front().second;
           q.pop();
           for(auto it:adj[node]){
              if(!visit[it]){
                  visit[it]=1;
                  q.push({it,node});
              }
              else if(parent!=-1 && it!=parent)return true;
           }
       }   
           }
       }
       
       return false;
    }
};