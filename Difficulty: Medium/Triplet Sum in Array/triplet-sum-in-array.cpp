class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
       vector<vector<int>> ans;
       sort(arr.begin(),arr.end());
       int l=0;int r=arr.size()-1;
       int sum=0;
       for(int i=0;i<arr.size();i++){
          l=i+1;r=arr.size()-1;
          while(l<r){
            sum=(arr[l]+arr[r]+arr[i]);
            if(sum==target){
                return true;
            }
            else if(sum<target)l++;
            else r--;
          }
       } 
       return false;
        
    }
};