// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        unordered_map<int,vector<int>> check;
        for(int i=0;i<arr.size();i++)check[arr[i]].push_back(i);
        priority_queue<int,vector<int>,greater<int>> q;
        int prev=-1;
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
        }
        int rank=0;
        vector<int> ans(arr.size(),0);
        while(!q.empty()){
            int curr=q.top();q.pop();
            if(prev!=curr){
                rank++;
                prev=curr;
                for(auto it:check[curr])ans[it]=rank;
            }
            // else continue;
        }
        return ans;
    }
};
