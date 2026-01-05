class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> q;
        for(int i=0;i<k;i++){
            q.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(q.top()>arr[i]){
                q.pop();
                q.push(arr[i]);
            }
        }
        return q.top();
    }
};