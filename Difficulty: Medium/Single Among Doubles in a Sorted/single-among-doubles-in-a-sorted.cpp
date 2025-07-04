class Solution {
  public:
    int findOnce(vector<int>& arr) {
        // code here.
        int low=0;int high=arr.size()-1;
        if(arr[low]!=arr[low+1])return arr[low];
        if(arr[high]!=arr[high-1])return arr[high];
        low++;high--;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])return arr[mid];
            if(arr[mid]==arr[mid-1] && mid%2!=0)low=mid+1;
            else if(arr[mid]==arr[mid-1] && mid%2==0)high=mid-1;
            else if(arr[mid]==arr[mid+1] && mid%2!=0)high=mid-1;
            else if(arr[mid]==arr[mid+1] && mid%2==0)low=mid+1;
        }
        return 0;
    }
};