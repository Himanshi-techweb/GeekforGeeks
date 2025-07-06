class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        // code here
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        if(k==1)return arr[0];
        for(auto it:arr)q.push(it);
        while(q.size()>1){
            vector<int> a=q.top();q.pop();
            vector<int> b=q.top();q.pop();
            a.insert(a.end(),b.begin(),b.end());
            sort(a.begin(),a.end());
            q.push(a);
        }
        return q.top();
    }
};