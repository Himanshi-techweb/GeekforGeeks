// User function Template for C++

class Solution {
  public:
     const int MOD=100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
       q.push({0,start});
       vector<int> dist(1e5 + 1,INT_MAX);
       dist[start]=0;
       while(!q.empty()){
           auto front=q.top();q.pop();
           int x=front.second;int step=front.first;
           if(x==end)return step;
           for(auto it:arr){
              int y=(x*it)%MOD;
              if(dist[y]>dist[x]+1){
                q.push({dist[x]+1,y});
                dist[y]=(dist[x]+1)%MOD;
              }
           }
       }
       return -1;
    }
};
