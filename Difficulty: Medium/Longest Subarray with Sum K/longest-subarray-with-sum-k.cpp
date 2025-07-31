class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> check;
        int sum=0;int ans=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k)ans=max(ans,i+1);
            if(check.find(sum-k)!=check.end()){
                ans=max(ans,i-check[sum-k]);
            }
            if(check.find(sum)==check.end())check[sum]=i;
        }
        
        return ans;
    }
};
// 94 -33 -13 40 -82 94 -33 -13 40 -82
// 52
// 10 -10 20 30