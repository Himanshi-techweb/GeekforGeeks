class Solution {
  public:
    bool check(int i,int n){
        int count=i/5 + i/25 + i/125 +i/625 + i/3125 + i/15625;
        return count>=n;
    }
    int findNum(int n) {
        // code here
        int l=5;int h=5*n;int ans=1;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid,n)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};