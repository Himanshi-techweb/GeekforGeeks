// User function Template for C++

class Solution {
  public:
    // vector<int> eventualSafeNodes(int V, ) {
    //     // code here
        
    // }
    // bool dfs(int i,vector<int> adj[],vector<int>&visit,vector<int> &path,vector<int>&safe){
    //     visit[i]=1;
    //     path[i]=1;
    //     for(auto it:adj[i]){
    //         if(!visit[it]){
    //             if(dfs(it,adj,visit,path,safe)){
    //                 return true;
    //             }
    //         }
    //         else if(path[it]==1)return true;
    //     }
    //     path[i]=0;
    //     safe.push_back(i);
    //     return false;
    // }
    // vector<int>  eventualSafeNodes(int V, vector<int> adj[]) {
    //     // code here
    //     vector<int> visit(V,0);
    //     vector<int> path(V,0);
    //     vector<int> safe;
    //     vector<vector<int>> arr(V);
    //     // for(int i=0;i<edge.size();i++){
    //     //     arr[edge[i][0]].push_back(edge[i][1]);
    //     // }
    //     for(int i=0;i<V;i++){
    //       if(!visit[i]){
    //         dfs(i,adj,visit,path,safe);    
    //       }
          
    //     }
    //     sort(safe.begin(),safe.end());
    //     return safe;
    // }
    
    
    vector<int>  eventualSafeNodes(int V, vector<int> adj[]){
       vector<int> in(V,0);
       vector<vector<int>> reverse(V);
       //vector<int> in(V,0);
       vector<int> result;
       queue<int> q;
       for(int i=0;i<V;i++){
           for(auto it:adj[i]){
            reverse[it].push_back(i);
            in[i]++;   
           }
       }
       
        for(int i=0;i<V;i++){
            if(in[i]==0){
                q.push(i);
                result.push_back(i);
            }
        }
        while(!q.empty()){
           int front=q.front();
           q.pop();
           for(auto it:reverse[front]){
               in[it]--;
               if(in[it]==0){
                   q.push(it);
                   result.push_back(it);
               }
           }
        }
        sort(result.begin(),result.end());
        return result;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};
