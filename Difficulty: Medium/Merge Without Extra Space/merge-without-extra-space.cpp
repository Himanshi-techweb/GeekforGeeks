class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int l=a.size()-1;int r=0;
        while(l>=0 && r<b.size()){
            if(a[l]>b[r]){
                swap(a[l],b[r]);
                l--;r++;
            }
            else break;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};