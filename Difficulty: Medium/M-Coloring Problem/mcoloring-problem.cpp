class Solution {
  public:
    bool ispossible(int node,int color,vector<vector<int>> &adj,vector<int> &check){
        if(node>=adj.size())return true;
        for(auto it:adj[node]){
            if(check[it]==color)return false;
        }
        return true;
    }
    bool solve(int node,int m,vector<vector<int>>&adj,vector<int> &check){
        if(node==adj.size())return true;
        for(int color=1;color<=m;color++){
            if(ispossible(node,color,adj,check)){
                check[node]=color;
                if(solve(node+1,m,adj,check))return true;
                check[node]=-1;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        vector<int> check(v,-1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return solve(0,m,adj,check);
    }
};