class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> check;
        int x=0;int cnt=0;
        check[0]=1;
        for(int i=0;i<arr.size();i++){
            x=x^arr[i];
            if(check.find(x^k)!=check.end()){
                cnt+=(check[x^k]);
            }
            check[x]++;
        }
        return cnt;
    }
};