class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int l=0;int r=0;int y=0;int mini=INT_MAX;
        while(r<arr.size()){
           y+=arr[r];
           while(y>x && l<arr.size()){
               mini=min(r-l+1,mini);
               y-=arr[l];l++;
           }
           r++;
        }
        return mini==INT_MAX?0:mini;
    }
};