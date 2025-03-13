//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // int count(vector<int>& coins, int sum) {
    //     // code here.
    // }
    int count( vector<int>& arr,int amount) {
        int n=arr.size();
        vector<vector<long long>> dp(n,vector<long long> (amount+1,0LL));
        
        dp[0][0]=0;
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int i=arr[0];i<=amount;i++){
            if(i%arr[0]==0)dp[0][i]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                long take=0LL;
                if(arr[i]<=a)take=dp[i][a-arr[i]];//it is the number of ways to make that coin not the minimum number of coin as we already adding how to make amount-arr[i] then n require to add 1 there
                long nottake=dp[i-1][a];
                dp[i][a]=take+nottake;
            }
        }
          return dp[n-1][amount];
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
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends