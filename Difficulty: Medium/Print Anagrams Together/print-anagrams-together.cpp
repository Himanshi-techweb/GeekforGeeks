// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        unordered_map<string,vector<string>> check;
        vector<vector<string>> ans;
        for(auto it:arr){
            string copy=it;
            sort(copy.begin(),copy.end());
            check[copy].push_back(it);
        }
        for(auto it:check){
            ans.push_back(it.second);
        }
        return ans;
    }
};