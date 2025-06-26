

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int m=arr.size();
        int maxi=arr[m-1];
        vector<int> ans;
        ans.push_back(maxi);
        for(int i=m-2;i>=0;i--){
          if(arr[i]>=maxi){
              maxi=arr[i];
              ans.push_back(arr[i]);
          }  
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};