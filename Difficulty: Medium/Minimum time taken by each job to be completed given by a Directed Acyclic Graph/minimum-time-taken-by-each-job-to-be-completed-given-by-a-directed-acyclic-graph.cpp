// User function Template for C++

class Solution {
  public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m) {
        // code here
        vector<int> in(n+1,0);
        in[0]=-1;
        vector<vector<int>> adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        vector<int> ans(n);
        vector<int>visit(n+1,0);
        queue<pair<int,int>> q;
        for(int i=1;i<=n;i++){
           if(in[i]==0){
               q.push({i,1});
               visit[i]=1;
               ans[i-1]=1;
           }
        }
        while(!q.empty()){
            auto front=q.front();q.pop();
            for(auto it:adj[front.first]){
                in[it]--;
                if(in[it]==0 && !visit[it]){
                    q.push({it,front.second+1});
                    ans[it-1]=front.second+1;
                    visit[it]=1;
                }
            }
        }
        return ans;
    }
};