
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int> arr(n,1);
        arr[1]=n-1;
        for(int i=2;i<n;i++){
          arr[i]=arr[i-1]*(n-i);
          arr[i]=arr[i]/(i);
        }
        return arr;
    }
};
