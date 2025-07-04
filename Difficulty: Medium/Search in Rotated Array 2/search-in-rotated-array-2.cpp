class Solution {
  public:
    bool Search(vector<int>& arr, int tar) {
        // Code here
        int low=0;int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==tar)return true;
            if(arr[low]!=tar && arr[high]!=tar ){
                low++;high--;
            }
            if(arr[mid]<arr[high]){
                if(tar>arr[mid] && tar<=arr[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                if(tar>=arr[low] && tar<arr[mid]){
                    high=mid-1;
                }
                else low=mid+1;
            }
        }
        return false;
    }
};