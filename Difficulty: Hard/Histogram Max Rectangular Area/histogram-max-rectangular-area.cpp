class Solution {
  public:
    vector<int> next_small(vector<int> &arr){
        stack<pair<int,int>> st;
        int n=arr.size();
        vector<int> nse(n,n);
        for(int i=n-1;i>=0;i--){
          while(!st.empty() && st.top().first>arr[i]){
              st.pop();
          } 
          if(!st.empty())nse[i]=st.top().second;
          st.push({arr[i],i});
        }
        return nse;
    }
    vector<int> previous_small(vector<int> &arr){
        stack<pair<int,int>> st;
        int n=arr.size();
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++){
          while(!st.empty() && st.top().first>=arr[i]){
              st.pop();
          } 
          if(!st.empty())pse[i]=st.top().second;
          st.push({arr[i],i});
        }
        return pse;
    }
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        int ans=0;
        vector<int> nse=next_small(arr);
        vector<int> pse=previous_small(arr);
        for(int i=0;i<n;i++){
            ans=max(ans,arr[i]*(nse[i]-pse[i]-1));
        }
        return ans;
    }
};
