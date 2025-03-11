//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool solve(int i,int tar,vector<int> &arr,vector<vector<int>> &dp){
        if(tar==0)return true;
        if(i==0)return arr[i]==tar;
        
        if(dp[i][tar]!=-1)return dp[i][tar];
        bool take=(tar>=arr[i])?solve(i-1,tar-arr[i],arr,dp):false;
        bool nottake=solve(i-1,tar,arr,dp);
        return dp[i][tar]=take || nottake;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,arr,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends