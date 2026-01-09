class Solution {
  public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        
        int l=-1;int mid=0;int high=arr.size()-1;
        while(mid<=high){
           if(arr[mid]<a){
               l++;
               swap(arr[l],arr[mid]);
               mid++;
           } 
           else if(arr[mid]>=a && arr[mid]<=b)mid++;
           else{
               
               swap(arr[high],arr[mid]);
               high--;
           }
        }

    }
};