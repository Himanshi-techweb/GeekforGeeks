class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int sum=0;int i=0;
        map<int,int> check;int mini=INT_MAX;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            check[sum]=i;
            if(sum>x){
              auto it=check.lower_bound(sum-x);
              if(it!=check.end()){
                  mini=min(mini,i-it->second+1);
              }
            }
            
        }
        return mini==INT_MAX?0:mini;
    }
};