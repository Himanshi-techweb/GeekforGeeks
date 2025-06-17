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
       vector<int> out(V,0);
       vector<vector<int>> arr(V);
       for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            arr[it].push_back(i);
            out[i]++;
        }   
       }
       queue<int> q;
       for(int i=0;i<V;i++){
           if(out[i]==0)q.push(i);
       }
       vector<int> t;
       while(!q.empty()){
           int front=q.front();
           t.push_back(front);
           q.pop();
           for(auto it:arr[front]){
               if(out[it]>0)out[it]--;
               if(out[it]==0)q.push(it);
           }
       }
       sort(t.begin(),t.end());
       return t;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};
