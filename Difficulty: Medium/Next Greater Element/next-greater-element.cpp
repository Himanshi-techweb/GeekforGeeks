class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<pair<int,int>> st;
        vector<int> nsg(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top().first<arr[i]){
                auto it=st.top();
                nsg[it.second]=arr[i];
                st.pop();
            }
            st.push({arr[i],i});
        }
        return nsg;
    }
};