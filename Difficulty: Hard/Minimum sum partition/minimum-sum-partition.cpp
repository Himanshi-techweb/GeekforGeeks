//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {

//   public:
//     int minDifference(vector<int>& arr) {
//         // Your code goes here
//     }
// };

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int sum=0;
        for(auto x:nums){
        sum+=x;
        } 
        int n=nums.size();        vector<vector<bool>> dp(n,vector<bool> (sum+1,false));
        for(int j=0;j<n;j++){
          dp[j][0]=true;
        }
        if(nums[0]<=sum)dp[0][nums[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                bool nottake=dp[i-1][j];
                bool take=(j>=nums[i])?dp[i-1][j-nums[i]]:false;
                 dp[i][j]=nottake || take; 
            }
        }
        int ans=1e8;
        for(int i=0;i<sum+1;i++){
            if(dp[n-1][i]==true){
                int s1=i;
                int s2=sum-s1;
                ans=min(ans,abs(s1-s2));
            }
        }
        return ans;

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

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends