class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        if(arr.size()==1)return 0;
        priority_queue<int,vector<int> ,greater<int>> q;
        for(auto it:arr)q.push(it);int ans=0;
        while(q.size()>1){
            int rope1=q.top();q.pop();
            int rope2=0;
            if(!q.empty()){
              rope2=q.top();q.pop();  
            }
            ans+=(rope1+rope2);
            q.push(rope1+rope2);
        }
        return ans;
    }
};