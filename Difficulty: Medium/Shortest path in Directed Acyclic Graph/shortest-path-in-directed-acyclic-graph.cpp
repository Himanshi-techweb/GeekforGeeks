// User function Template for C++
class Solution {
  public:
    void dfs(int i,vector<vector<pair<int,int>>> &arr,stack<int> &st,vector<int>&visit){
        visit[i]=1;
        //path[1]=0;
        for(auto it:arr[i]){
            if(!visit[it.first]){
                dfs(it.first,arr,st,visit);
            }
        }
        st.push(i);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edge) {
        // code here
        vector<int> dist(V,INT_MAX);
        vector<vector<pair<int,int>>>arr(V);
        stack<int> st;
        for(int i=0;i<E;i++){
            int x=edge[i][0];
            int y=edge[i][1];
            int w=edge[i][2];
            arr[x].push_back({y,w});
            
        }
        vector<int> visit(V,0);
        for(int i=0;i<V;i++){
            if(!visit[i])dfs(i,arr,st,visit);
        }
        //vector<int> sort;
        dist[0]=0;
        while(!st.empty()){
            int front=st.top();
            st.pop();
            if(dist[front]!=INT_MAX){
              for(auto it:arr[front]){
               dist[it.first]=min(dist[it.first],dist[front]+it.second); 
               
              }  
            }
        }
        
        for(auto &it:dist){
            if(it==INT_MAX)it=-1;
        }
        return dist;
    }
};
