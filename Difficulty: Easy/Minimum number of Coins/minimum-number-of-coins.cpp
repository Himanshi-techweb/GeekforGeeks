// User function Template for C++

class Solution {
  public:
    int solve(int i, int w, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == 0) {
        if (w % arr[0] == 0) return dp[i][w] = w / arr[0];
        else return dp[i][w] = INT_MAX;
    }
    if (dp[i][w] != -1) return dp[i][w];

    int take = INT_MAX;
    if (w >= arr[i])
        take = 1 + solve(i, w - arr[i], arr, dp);

    int nottake = solve(i - 1, w, arr, dp);

    return dp[i][w] = min(take, nottake);
}

    void reconstruct(int i, int w, vector<int>& arr, vector<vector<int>>& dp, vector<int>& ans) {
    while (i >= 0 && w > 0) {
        if (i == 0) {
            while (w >= arr[0]) {
                ans.push_back(arr[0]);
                w -= arr[0];
            }
            return;
        }
        if (w >= arr[i] && dp[i][w] == 1 + dp[i][w - arr[i]]) {
            ans.push_back(arr[i]);
            w -= arr[i];
        } else {
            i--;
        }
    }
    }
    vector<int> minPartition(int N) {
        // code here
        int m=10;
        vector<int> ans;
        vector<vector<int>> dp(m,vector<int>(N+1,-1));
        vector<int> arr={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        solve(m-1,N,arr,dp);
        reconstruct(arr.size() - 1, N, arr, dp, ans);
        return ans;
    }
};