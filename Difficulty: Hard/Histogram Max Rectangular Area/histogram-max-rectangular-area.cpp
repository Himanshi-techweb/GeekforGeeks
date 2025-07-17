class Solution {
  public:
    int n;
    vector<int> previoussmaller(vector<int>& arr){
        vector<int> pse(n,-1);
        stack<pair<int,int>> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first>arr[i]){
                auto it=st.top();st.pop();
                pse[it.second]=i;
            }
            st.push({arr[i],i});
        }
        return pse;
    }
    vector<int> nextsmaller(vector<int>& arr){
        vector<int> nse(n,n);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>arr[i]){
                auto it=st.top();st.pop();
                nse[it.second]=i;
            }
            st.push({arr[i],i});
        }
        return nse;
    }
    int getMaxArea(vector<int> &arr) {
        // Your code here
        n=arr.size();int ans=INT_MIN;
        vector<int> pse=previoussmaller(arr);
        vector<int> nse=nextsmaller(arr);
        for(int i=0;i<arr.size();i++){
          ans=max(ans,arr[i]*(nse[i]-pse[i]-1));  
        }
        return ans;
    }
};
