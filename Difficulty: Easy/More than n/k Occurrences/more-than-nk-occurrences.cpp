class Solution {
  public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
        // Your code here
        unordered_map<int,int> check;
        for(int i=0;i<arr.size();i++){
            check[arr[i]]++;
        }
        int req=arr.size()/k;
        int cnt=0;
        for(auto it:check){
            if(it.second>req)cnt++;
        }
        return cnt;
    }
};