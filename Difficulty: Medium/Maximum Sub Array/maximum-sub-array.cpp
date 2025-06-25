// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        int maxi=0;int sum=0;
        vector<int> ans;
        vector<int> temp;
        for(int i=0;i<arr.size();i++){
           if(arr[i]<0){
               if(sum>maxi){
                   ans=temp;
                   maxi=sum;
               }
               sum=0;
               temp={};
           }
           else{
               temp.push_back(arr[i]);
               sum+=arr[i];
           }
        }
        if(sum>maxi)ans=temp;
        if(ans.size()==0)return {-1};
        return ans;
    }
};