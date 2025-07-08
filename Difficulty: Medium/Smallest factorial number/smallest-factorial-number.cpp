
class Solution {
  public:
    int  cnttrailingzero(int x){
       int cnt=0;
       while(x>0){
           x=x/5;
           cnt+=x;
       }
       return cnt;
    }
    int findNum(int n) {
        // complete the function here
        int low=0;int high=5*n;int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=cnttrailingzero(mid);
            if(cnt>=n){
                ans=mid;high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};