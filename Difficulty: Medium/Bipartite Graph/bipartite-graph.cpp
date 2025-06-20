class Solution {
  public:
    bool dfs(int i,int parent,vector<vector<int>> &arr,vector<int> &color,vector<int> &visit){
        visit[i]=1;
        for(auto it:arr[i]){
            if(!visit[it] ){
                color[it]=!color[i];
                if(!dfs(it,i,arr,color,visit))return false;
            }
            else if(it !=parent && color[it]==color[i])return false;
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edge) {
        // Code here
        vector<int> color(V,-1);
        vector<vector<int>> arr(V);
        vector<int> visit(V,0);
        for(auto it:edge){
            arr[it[0]].push_back(it[1]);
            arr[it[1]].push_back(it[0]);
        }
        for(int i=0;i<V;i++){
            if(!visit[i]){
                color[i]=0;
                if(!dfs(i,-1,arr,color,visit)) return false;
            }
        }
        return true;
    }
};