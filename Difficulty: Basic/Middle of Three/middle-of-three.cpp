// User function template for C++

class Solution {
  public:
    int middle(int a, int b, int c) {
        // code here
        int mini=min({a,b,c});
        if(mini==a){
            return min(b,c);
        }
        if(mini==b){
            return min(a,c);
        }
        if(mini==c){
            return min(b,a);
        }
        return -1;
    }
};