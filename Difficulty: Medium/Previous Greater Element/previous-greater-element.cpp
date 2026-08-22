class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top()<=arr[i])st.pop();
            ans[i]=(st.empty())?-1:st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};