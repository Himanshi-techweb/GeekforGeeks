

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        ans.push_back(arr[arr.size()-1]);
        int maxi=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0 ;i--){
          if(arr[i]>=maxi){
              ans.push_back(arr[i]);
              maxi=arr[i];
          }  
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};