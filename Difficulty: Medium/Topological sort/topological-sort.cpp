class Solution {
  public:
    stack<int> st;
    // void dfs(int i,vector<int> &visit,vector<int> &pathvisit,vector<vector<int>> &adj){
    //     visit[i]=1;pathvisit[i]=1;
    //     for(auto it:adj[i]){
    //         if(!visit[it]){
    //             visit[it]=1;
    //             dfs(it,visit,pathvisit,adj);
    //         }
    //     }
    //     st.push(i);
    //     pathvisit[i]=0;
    // }
    // vector<int> topoSort(int V, vector<vector<int>>& edges) {
    //     // code here
    //     vector<vector<int>> adj(V);
    //     for(auto it:edges)adj[it[0]].push_back(it[1]);
    //     vector<int> visit(V,0);
    //     vector<int> pathvisit(V,0);
    //     vector<int> ans;
    //     for(int i=0;i<V;i++){
    //       if(!visit[i]){
    //         dfs(i,visit,pathvisit,adj);   
    //       }
    //     }
    //     while(!st.empty()){
    //       ans.push_back(st.top());
    //       st.pop();
    //     }
    //     // reverse(ans.begin(),ans.end());
    //     return ans;
    // }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> in(V,0);
        queue<int> q;
        vector<int> ans;
        for(auto it:edges){
          adj[it[0]].push_back(it[1]);
          in[it[1]]++;
        }
        for(int i=0;i<V;i++){
            if(in[i]==0)q.push(i);
        }
        while(!q.empty()){
            auto front=q.front();q.pop();
            ans.push_back(front);
            for(auto it:adj[front]){
              in[it]--;
              if(in[it]==0)q.push(it);
            }
        }
        return ans;
    }   
};