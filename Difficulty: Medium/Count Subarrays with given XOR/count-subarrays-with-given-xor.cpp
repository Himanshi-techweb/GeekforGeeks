class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long long cnt=0;
        unordered_map<int,int> check;int xr=0;
        // check[0]=1;
        for(int i=0;i<arr.size();i++){
           xr=xr^arr[i];
           int x=xr^k;
           if(xr==k)cnt++;
           if(check.find(x)!=check.end()){
               cnt+=(check[x]);
           }
           check[xr]++;
        }
        return cnt;
    }
};