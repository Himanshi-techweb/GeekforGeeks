// User function Template for C++

class Solution {
  public:
    // vector<int> eventualSafeNodes(int V, ) {
    //     // code here
        
    // }
    bool dfs(int i,vector<int> adj[],vector<int>&visit,vector<int> &path,vector<int>&safe){
        visit[i]=1;
        path[i]=1;
        for(auto it:adj[i]){
            if(!visit[it]){
                if(dfs(it,adj,visit,path,safe)){
                    return true;
                }
            }
            else if(path[it]==1)return true;
        }
        path[i]=0;
        safe.push_back(i);
        return false;
    }
    vector<int>  eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> visit(V,0);
        vector<int> path(V,0);
        vector<int> safe;
        vector<vector<int>> arr(V);
        // for(int i=0;i<edge.size();i++){
        //     arr[edge[i][0]].push_back(edge[i][1]);
        // }
        for(int i=0;i<V;i++){
          if(!visit[i]){
            dfs(i,adj,visit,path,safe);    
          }
          
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};
