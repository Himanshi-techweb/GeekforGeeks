class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edge) {
        // Code here
        queue<pair<int,int>>q;
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
            vis[i]=1;
            q.push({i,-1});
            while(!q.empty()){
                int size=q.size();
                for(int i=0;i<size;i++){
                   pair<int,int> front=q.front();q.pop();
                   int node=front.first;int parent=front.second;
                    for(auto it:arr[node]){
                        if(it!=parent && vis[it]){
                            return true;  
                        } 
                        else if(!vis[it]){
                           q.push({it,node});
                           vis[it]=1;
                        }
                    }
                }
            }   
          }
          
        }
        
        return false;
    }
};