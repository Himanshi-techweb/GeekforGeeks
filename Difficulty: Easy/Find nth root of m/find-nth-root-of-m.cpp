class Solution {
  public:
    int check(int n,int m){
        int ans=1;
        while(n>0){
            if(n%2!=0){
                ans=ans*m;
                n=n-1;
            }
            else{
                m=m*m;
                n=n/2;
            }
        }
        return ans;
    }
    int nthRoot(int n, int m) {
        // Code here.
        int l=1;
        int h=m;
        while(l<=h){
            int mid=l+(h-l)/2;
            int expo=check(n,mid);
            if(expo==m)return mid;
            if(expo<m)l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};