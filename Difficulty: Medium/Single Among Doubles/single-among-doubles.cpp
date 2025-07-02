// User function template for C++
class Solution {
  public:
    int search(int n, int arr[]) {
        // code
        int low=0;int high=n-1;
        while(low<=high){
            int mid= low + (high-low)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])return arr[mid];
            if(mid%2==0 && arr[mid]==arr[mid+1])low=mid+1;
            else if(mid%2==0 && arr[mid]==arr[mid-1])high=mid-1;
            else if(mid%2!=0 && arr[mid]==arr[mid-1])low=mid+1;
            else high=mid-1;
        }
        return arr[low];
    }
};