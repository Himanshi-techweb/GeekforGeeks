// User function Template for C++

class Solution {
  public:
    int solve(int i,vector<int> &arr){
        int cnt=0;
        // stack<int> st;
        for(int k=i+1;k<arr.size();k++){
            if(arr[k]>arr[i])cnt++;
        }
        return cnt;
    }
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // write your code here
        vector<int> ans;
        for(auto it:indices){
           ans.push_back(solve(it,arr)); 
        }
        return ans;
    }
};