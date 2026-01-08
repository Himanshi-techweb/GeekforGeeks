// User function template for C++

class Solution {
  public:
    void multiply(int i,vector<int> &arr){
      int carry=0;int r=0;int y=0;
      vector<int> check;
      for(int j=0;j<arr.size();j++){
          y=i*arr[j];
          y=y+carry;carry=0;
          r=y%10;int q=y/10;
          check.push_back(r);
          carry+=q;
      }
      if(carry>0){
          while(carry>0){
              r=carry%10;carry=carry/10;
              check.push_back(r);
          }
      }
      arr=check;
    }
    vector<int> factorial(int n) {
        // code here
        
        if(n==1)return {1};
        int k=n;
        vector<int> arr;
        //store entire bits of n
        while(k>0){
            int r=k%10;
            k=k/10;
            arr.push_back(r);
        }
        for(int i=n-1;i>=1;i--){
            multiply(i,arr);
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};