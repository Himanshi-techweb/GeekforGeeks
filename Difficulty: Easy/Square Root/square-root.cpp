class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int low=1;int high=n;int sqr=1;
        while (low<=high){
            int mid=low+(high-low)/2;
            if(mid*mid==n)return mid;
            if(mid*mid<n){
              sqr=mid;
              low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return sqr;
    }
};