// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        vector<int> check(1e5,INT_MAX);
        q.push({0,start});
        check[start]=0;
        while(!q.empty()){
            int level=q.front().first;
            int node=q.front().second;
           // if(node==end)return level;
            q.pop();
            for(int i=0;i<arr.size();i++){
                int newstart=(node*arr[i])%100000;
                if(check[newstart]>level+1){
                    q.push({level+1,newstart});
                    if(newstart==end)return level+1;
                    check[newstart]=level+1;
                }
            }
        }
        if(check[end]!=INT_MAX)return check[end];
        return -1;
    }
};
