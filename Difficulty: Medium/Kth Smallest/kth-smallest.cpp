// User function template for C++

class Solution {
  public:
    
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> q;
        for(int i=0;i<k;i++){
            q.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(arr[i]<q.top()){
                q.pop();
                q.push(arr[i]);
            }
        }
        return q.top();
    }
};