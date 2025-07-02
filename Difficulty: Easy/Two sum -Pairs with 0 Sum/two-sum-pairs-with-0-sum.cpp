// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        int i=0;int j=arr.size()-1;
        while(i<j){
            if(arr[i]+arr[j]==0){
                st.insert({arr[i],arr[j]});
                i++;
                j--;
            }
            else if(arr[i]+arr[j]<0){
               i++;  
            }
            else j--;
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};