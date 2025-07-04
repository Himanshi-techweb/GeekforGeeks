// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low=0;int high=arr.size()-1;
        int mini=INT_MAX;int ix=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<arr[high]){
                if(arr[mid]<mini){
                    mini=arr[mid];ix=mid;
                }
                high=mid-1;
            }
            else{
               if(arr[low]<mini){
                    mini=arr[low];ix=low;
                }
               low=mid+1;
            }
        }
        return ix;
    }
};
