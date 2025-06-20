class Solution {
  public:
    bool dfs(int i,vector<vector<int>> &arr,vector<int> &visit,vector<int> &path){
        visit[i]=1;
        path[i]=1;
        for(auto it:arr[i]){
            if(!visit[it]){
                if(dfs(it,arr,visit,path)) return true;
            }
            else if(path[it]==1){
                return true;
            }
        }
        path[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edge) {
       vector<vector<int>> arr(V);
       for(auto it:edge){
           arr[it[0]].push_back(it[1]);
       }
       vector<int> visit(V,0);
       vector<int> path(V,0);
       for(int i=0;i<V;i++){
           if(!visit[i]){
               if(dfs(i,arr,visit,path)) return true;
           }
       }
       return false;
    }
};































