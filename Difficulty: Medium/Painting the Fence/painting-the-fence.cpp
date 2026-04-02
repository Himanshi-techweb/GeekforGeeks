class Solution {
  public:
    int count(int i,int color,int colorcount,int n,int k){
        if(i==n)return 1;
        // if(color>=k || i>=n)return INT_MIN;
        int counts=0;
        int notsamecolor=0;
        for(int j=0;j<k;j++){
           //color change 
           if(j==color && colorcount>=2)continue;
           else if(j==color && colorcount<2){
               counts+=count(i+1,color,colorcount+1,n,k);
           }
           
           else counts+=count(i+1,j,1,n,k);
       } 
       return counts;
    }
    int countWays(int n, int k) {
        // code here
        // return count(0,-1,0,n,k);
        if(n==1)return k;
        int same=0;int diff=k;
        for(int i=2;i<=n;i++){
            int newsame=diff;
            int newdiff=(same+diff)*(k-1);
            same=newsame;
            diff=newdiff;
        }
        return diff+same;
    }
};