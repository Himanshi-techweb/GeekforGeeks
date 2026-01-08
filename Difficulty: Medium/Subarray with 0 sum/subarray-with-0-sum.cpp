class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> check;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)return true;
            sum+=arr[i];
            if(sum==0 || check.find(sum)!=check.end())return true;
            check[sum]++;
        }
        return false;
    }
};