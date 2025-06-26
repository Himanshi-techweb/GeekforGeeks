class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<int> curr=arr[0];
        vector<vector<int>> ans;
        for(int i=1;i<arr.size();i++){
          if(arr[i][0]<=curr[1]){
              curr[1]=max(curr[1],arr[i][1]);
          }  
          else{
              ans.push_back(curr);
              curr=arr[i];
          }
        }
        ans.push_back(curr);
        return ans;
    }
};