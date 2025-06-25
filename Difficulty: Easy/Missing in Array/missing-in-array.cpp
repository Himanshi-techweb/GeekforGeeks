class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n=arr.size();
        long long sum1=(n+1)*(n+2LL)/2;
        long long sum2=accumulate(arr.begin(),arr.end(),0LL);
        return sum1-sum2;
    }
};