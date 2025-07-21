class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        vector<int> in(n,0);
        vector<vector<int>> adj(n);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        vector<int>visit(n,0);
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
           if(in[i]==0){
               q.push(i);
               ans.push_back(i);
               visit[i]=1;
           }
        }
         while(!q.empty()){
            auto front=q.front();q.pop();
            for(auto it:adj[front]){
                in[it]--;
                if(in[it]==0 && !visit[it]){
                    q.push(it);
                    ans.push_back(it);
                    visit[it]=1;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        // for(auto it:ans){
        //     cout<<it<<" "<<endl;
        // }
        return ans;
    }
};