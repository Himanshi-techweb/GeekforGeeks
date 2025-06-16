class Solution {
  public:
    bool condition=false;bool condition2=false;
    bool dfs(int src,int parent,vector<vector<int>>&arr,vector<int> &vis){
        vis[src]=1;
        for(auto it:arr[src]){
            if(!vis[it]){
                condition= dfs(it,src,arr,vis);
            }
            else if(it!=parent){
                condition2=true;
            }
        }
        return condition||condition2;
    }
    bool isCycle(int V, vector<vector<int>>& edge) {
        // Code here
        int e=edge.size();
        vector<vector<int>> arr(V);
        for(int i=0;i<e;i++){
          int j=edge[i][0];
          int k=edge[i][1];
          arr[j].push_back(k);
          arr[k].push_back(j);
        }
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,arr,vis))return true;
            }
        }
        return false;
    }
};