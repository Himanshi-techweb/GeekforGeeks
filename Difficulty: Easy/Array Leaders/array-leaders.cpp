

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int maxi=arr[arr.size()-1];
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]>maxi)maxi=arr[i];
            if(arr[i]>=maxi){
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};