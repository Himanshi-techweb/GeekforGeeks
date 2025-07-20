// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int l=0;int r=arr.size()-1;int cnt=0;
        while(l<r){
           if(arr[l]>k && arr[r]<=k){
               cnt++;
               swap(arr[l],arr[r]);
               l++;r--;
           } 
           else if(arr[l]<=k)l++;
           else r--;
        }
        return cnt;
    }
};
