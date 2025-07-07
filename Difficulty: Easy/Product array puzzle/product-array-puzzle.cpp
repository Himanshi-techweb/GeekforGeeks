// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        int pre=1;int suf=1;
        vector<int> ans(n,0);int cnt_0=0;int mult=1;
        for(int i=0;i<n;i++){
           if(arr[i]!=0)mult=mult*arr[i];
           if(arr[i]==0)cnt_0++; 
        }
        if(cnt_0==0){
           for(int i=0;i<arr.size();i++){
             ans[i]=mult/arr[i];
           } 
        }
        else if(cnt_0==1){
          for(int i=0;i<arr.size();i++){
            if(arr[i]==0)ans[i]=mult;
            else ans[i]=0;
          }
        }
        return ans;
    }
};
