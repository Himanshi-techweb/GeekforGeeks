// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
       unordered_map<int,int> check;
       int ans=0;int sum=0;
       for(int i=0;i<arr.size();i++){
           sum+=arr[i];
           if(sum==k)ans++;
           int temp=sum-k;
           if(check.find(temp)!=check.end()){
               ans+=check[temp];
           }
            check[sum]++;
       }
       return ans;
    }
};