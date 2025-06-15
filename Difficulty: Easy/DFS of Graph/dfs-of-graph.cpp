class Solution {
  public:
    vector<int> arr;
    void dfs(int i,vector<int>&visit,vector<vector<int>>&adj){
        visit[i]=1;
        arr.push_back(i);
        for(auto it:adj[i]){
                if(visit[it]==0){
                  dfs(it,visit,adj);  
                }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int x=adj.size();
        vector<int> visit(x+1,0);
       // vector<int> arr();
        for(int i=0;i<x;i++){
           if(visit[i]==0){
               visit[i]=1;
               dfs(i,visit,adj);
           } 
        }
        return arr;
    }
};