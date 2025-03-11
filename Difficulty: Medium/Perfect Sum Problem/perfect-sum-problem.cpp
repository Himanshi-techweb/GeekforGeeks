//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int perfectSum(vector<int>& nums, int tar) {
     int n=nums.size();
        // int tar=sum/2;
        vector<vector<int>> dp(n,vector<int> (tar+1,false));
        vector<int>prev(tar+1,0);
        vector<int> curr(tar+1);
        prev[0]=curr[0]=1;
        //  return solve(n-1,tar,nums,dp);
        // for(int j=0;j<n;j++){
        //   prev[0]=1;
        // }
        if(nums[0]<=tar)prev[nums[0]]+=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                int nottake=prev[j];
                int take=(j>=nums[i])?prev[j-nums[i]]:0;
                 curr[j]=nottake + take; 
            }prev=curr;
        }
        
        return prev[tar];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends