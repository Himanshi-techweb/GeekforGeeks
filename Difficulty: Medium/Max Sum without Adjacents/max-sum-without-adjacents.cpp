//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int solve(vector<int> & arr,vector<int> &dp,int idx){
        if(idx>=arr.size())return 0; 
        if(dp[idx]!=-1)return dp[idx];
        int include=solve(arr,dp,idx+2)+arr[idx];
        int exclude=solve(arr,dp,idx+1)+0;
        int ans=max(include,exclude);
        return dp[idx]=ans;
    }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        vector<int> dp(arr.size()+1,-1);
        return solve(arr,dp,0);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.findMaxSum(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends