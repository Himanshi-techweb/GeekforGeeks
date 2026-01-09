// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int count=0;
        for(auto t:arr){
            if(t<=k)count++;
        }
        if(count==0)return 0;
        int l=0;int r=0;int mini=INT_MAX;
        int t=0;
        while(r<count){
            if(arr[r]>k)t++;
            r++;
        }
        mini=min(mini,t);
        while(r<arr.size()){
            if(arr[l]>k)t--;
            l++;
            if(arr[r]>k)t++;
            mini=min(mini,t);
            r++;
        }
        return mini==INT_MAX?0:mini;
    }
};
