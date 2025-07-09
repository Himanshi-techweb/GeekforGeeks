// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int i=0;int j=arr.size()-1;
        while(i<j){
          int sum=arr[i]+arr[j];
          if(sum==0){
              int a=arr[i];int b=arr[j];
              ans.push_back({a,b});
              while(i<j && arr[i]==a)i++;
              while(i<j && arr[j]==b)j--;
          }
          else if(sum>0)j--;
          else i++;
        }
        return ans;
    }
};