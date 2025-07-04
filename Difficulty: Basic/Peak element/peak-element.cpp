class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int low=0;int high=arr.size()-1;
        if(arr[0]>arr[1])return 0;
        if(arr[high]>arr[high-1])return high;
        low++;high--;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return mid;
            if(arr[mid]>arr[mid-1])low=mid+1;
            else if(arr[mid]<arr[mid-1])high=mid-1;
            else if(arr[mid]>arr[mid+1])high=mid-1;
            else if(arr[mid]<arr[mid+1])low=mid+1;
        }
        return 0;
    }
};