class Solution {
  public:
    long long power(int x, int n) {
        long long N = n;  // To handle negative exponents safely
        int result = 1;
        while (N > 0) {
            if (N % 2 == 1) {
               result *= x;
            }
            x *= x;
            N /= 2;
        }

    return result;
    }

    int nthRoot(int n, int m) {
        // Code here
        if(n==1)return m;
        int low=1;int high=m;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long val=power(mid,n);
            if(val==m){
              return mid;
            }
            else if(val<m)low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};