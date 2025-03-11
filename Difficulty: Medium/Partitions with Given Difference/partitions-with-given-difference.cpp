//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPartitions(vector<int>& nums, int d) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        //sum1-sum2=d//sum1=sum-sum2//sum1=(total-d)/2;
        //tar=(sum-d)/2;
        if((sum-d)%2!=0 || sum<d)return 0;
        int tar=(sum-d)/2;
        vector<vector<int>> dp(n,vector<int> (tar+1,0));
        if(nums[0]==0){
            dp[0][0]=2;
        }
        else{
          dp[0][0]=1;  
        }
        if(nums[0]!=0 && nums[0]<=tar){
            dp[0][nums[0]]=1;
        }
        for(int i=1;i<n;i++){
          for(int j=0;j<=tar;j++){
              int nottake=dp[i-1][j];
              int take=(nums[i]<=j)?dp[i-1][j-nums[i]]:0;
              dp[i][j]=take+nottake;
          }  
        }
        //cout<<dp[n-1][tar]<<endl;
        return dp[n-1][tar];
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends