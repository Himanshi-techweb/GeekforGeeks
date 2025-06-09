class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int low=1;
        int high=m;
        while(low<=high){
            int mid= low + (high-low)/2;
            long long check=1;
            for(int i=1;i<=n;i++){
                check=check*mid;
            }
            if(check==m)return mid;
            if(check>m)high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};