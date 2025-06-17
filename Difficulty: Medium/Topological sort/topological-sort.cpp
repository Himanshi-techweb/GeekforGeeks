class Solution {
  public:
    void dfs(int i,vector<vector<int>>&arr,vector<int>&visit,stack<int>&st){
        visit[i]=1;
        for(auto it:arr[i]){
            if(!visit[it]){
              dfs(it,arr,visit,st);  
            }
        }
        st.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edge) {
        // code here
        vector<vector<int>> arr(V);
        for(int i=0;i<edge.size();i++){
            arr[edge[i][0]].push_back(edge[i][1]);
            
        }
            stack<int> st;
            vector<int> visit(V,0);
            for(int i=0;i<V;i++){
                if(!visit[i]){
                    dfs(i,arr,visit,st);
                }
            }
        vector<int> topo;
        while(!st.empty()){
           topo.push_back(st.top());
           st.pop();
        }
        return topo;
    }
};