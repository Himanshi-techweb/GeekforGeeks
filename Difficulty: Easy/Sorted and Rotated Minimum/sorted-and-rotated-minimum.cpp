class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int low=0;int high=arr.size()-1;
        int mini=INT_MAX;
       while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<arr[high]){
                mini=min(mini,arr[mid]);
                high=mid-1;
            }
            else{
               mini=min(mini,arr[low]); 
               low=mid+1;
            }
        }
        return mini;
    }
};