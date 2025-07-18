class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        stack<int> st;
        vector<int> ans(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top()>=arr[i])st.pop();
            if(!st.empty())ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};