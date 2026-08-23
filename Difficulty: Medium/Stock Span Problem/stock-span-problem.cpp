class Solution {
  public:
    vector<int> nge(vector<int>&arr){
        stack<int> st;
        vector<int> t(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
            t[i]=(st.empty())?arr.size():st.top();
            st.push(i);
        }
        return t;
    }
    vector<int> pge(vector<int>&arr){
        stack<int> st;
        vector<int> t(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
            t[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return t;
    }
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        vector<int> ans(arr.size(),0);
        vector<int> ngearr=nge(arr);
        vector<int> pgearr=pge(arr);
        for(int i=0;i<arr.size();i++){
            ans[i]=(i-pgearr[i]);
        }
        return ans;
        
    }
};