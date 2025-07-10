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
        int ans=0;
        vector<int> ns=next_small(arr);
        vector<int> ps=previous_small(arr);
        for(int i=0;i<arr.size();i++){
           ans=max(ans,(ns[i]-ps[i]-1)*arr[i]); 
        }
        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
        vector<vector<int>> check(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
               cnt+=1;
               if(mat[j][i]==0){
                   cnt=0;
               }
               check[j][i]=cnt;
            }
            
        }
        for(int i=0;i<m;i++){
            ans=max(ans,getMaxArea(check[i]));
        }
        return ans;
    }
};