class Solution {
  public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        int low=0;int high=arr.size()-1;int mid=0;
        while(mid<=high){
            if(arr[mid]<a){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]>=a && arr[mid]<=b){
                mid++;
            }
            else if(arr[mid]>b){
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};