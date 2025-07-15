//Back-end complete function Template for C++

class Solution {
  public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n);
        set<int> check;
        for(int i=n-1;i>=0;i--){
            auto ub=check.upper_bound(arr[i]);
            if(ub!=check.end())ans[i]=*ub;
            else ans[i]=-1;
            check.insert(arr[i]);
        }
        return ans;
    }
};