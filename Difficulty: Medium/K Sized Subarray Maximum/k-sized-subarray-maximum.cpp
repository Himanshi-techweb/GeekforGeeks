class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int> q(k);
        vector<int> ans;
        for(int i=0;i<k;i++){
            while(!q.empty() && arr[i]>=arr[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        
        for(int i=k;i<arr.size();i++){
            ans.push_back(arr[q.front()]);
            while(!q.empty() && q.front()<=i-k)q.pop_front();
            while(!q.empty() && arr[i]>=arr[q.back()])q.pop_back();
            q.push_back(i);
        }
        ans.push_back(arr[q.front()]);
        return ans;
    }
};