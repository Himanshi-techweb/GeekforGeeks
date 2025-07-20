class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int l=0;int r=m-1;int mini=a[r]-a[l];
        while(l<=r && r<a.size()){
           mini=min(mini,a[r]-a[l]);
           l++;r++;
        }
        return mini;
        
    }
};