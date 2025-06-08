// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low=0;int i=0;
      int high=arr.size()-1;
      int ans=INT_MAX;
      if(arr[low]<=arr[high])return 0;
      while(low<=high){
        int mid=low + (high-low)/2;
        if(arr[low]<=arr[mid]){
        //   ans=min(ans,arr[low]);
        //   i=low;
        if(arr[low]<ans){
         i=low;
         ans=arr[low];
        }
          low=mid+1; 
        }//left sorted
        else{
            // ans=min(ans,arr[mid]);
            if(arr[mid]<ans){
              i=mid;
              ans=arr[mid];
            }
            //i=mid;
            high=mid-1;
        }
      } 
      return i; 
    }
};
