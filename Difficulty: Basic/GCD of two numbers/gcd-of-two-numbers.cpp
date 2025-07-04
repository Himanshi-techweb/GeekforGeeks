class Solution {
  public:
    
    int gcd(int a, int b) {
        // code here
        if(a==0)return b;
        if(b==0)return a;
        if(a>b) return gcd(a%b,b);
        else return gcd(b%a,a);
    }
};
