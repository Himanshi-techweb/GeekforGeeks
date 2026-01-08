class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int maxsofar=arr[0];
        int maxend=arr[0];
        int minend=arr[0];
        int tempmax=arr[0];int tempmin=arr[0];
        for(int i=1;i<arr.size();i++){
            tempmax=max({arr[i],arr[i]*maxend,arr[i]*minend});
            tempmin=min({arr[i],arr[i]*maxend,arr[i]*minend});
            maxend=tempmax;minend=tempmin;
            maxsofar=max(maxsofar,maxend);
        }
        
        return maxsofar;
    }
};