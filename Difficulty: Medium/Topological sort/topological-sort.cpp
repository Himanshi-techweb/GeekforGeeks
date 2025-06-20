class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edge) {
        // code here
        vector<vector<int>> arr(V);
        vector<int> visit(V,0);
        vector<int> result;
        vector<int> in(V,0);
        queue<int> q;
        for(auto it:edge){
            arr[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        for(int i=0;i<V;i++){
            if(in[i]==0){
                q.push(i);
                result.push_back(i);
                visit[i]=1;
            }
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto it:arr[front]){
                if(!visit[it]){
                    in[it]--;
                    if(in[it]==0){
                        result.push_back(it);
                        q.push(it);
                        visit[it]=1;
                    }
                    
                }
            }
        }
        return result;
    }
};