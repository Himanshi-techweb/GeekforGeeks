class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<k;i++){
            q.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(arr[i]>q.top()){
                q.pop();
                q.push(arr[i]);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top());q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};