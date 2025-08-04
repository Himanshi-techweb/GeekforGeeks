//Position this line where user code will be pasted.
class Solution {
  public:
    stack<int> st;
    void dfs(int i,vector<vector<int>> &adj,vector<int> &visit){
        for(auto it:adj[i]){
            if(!visit[it]){
              visit[it]=1;
              dfs(it,adj,visit);  
            }
        }
        st.push(i);
    }
    void dfs2(int i,vector<vector<int>> &adj,vector<int> &visit){
        for(auto it:adj[i]){
            if(!visit[it]){
              visit[it]=1;
              dfs(it,adj,visit);  
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int size=adj.size();
        vector<int> visit(size,0);
        //sort the graph according to finishing time
        for(int i=0;i<size;i++){
            if(!visit[i]){
                visit[i]=1;
                dfs(i,adj,visit);
            }
        }
        
        //reverse graph
        vector<vector<int>> reversegraph(size);
        for(int i=0;i<size;i++){
            for(auto it:adj[i]){
                reversegraph[it].push_back(i);
            }
        }
        
        //then dfs
        int cnt=0;
        vector<int> new_visit(size,0);
        while(!st.empty()){
            auto i=st.top();st.pop();
            if(!new_visit[i]){
                cnt++;
                new_visit[i]=1;
                dfs2(i,reversegraph,new_visit);
            }
        }
        return cnt;
    }
};