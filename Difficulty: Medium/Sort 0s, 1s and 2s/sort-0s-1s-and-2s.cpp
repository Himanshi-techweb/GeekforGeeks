class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int low=-1;
        int high=arr.size();
        int mid=0;
        int i=0;
         while(mid<high){
            if(arr[mid]==0){
                swap(arr[mid],arr[low+1]);
                low++;
                mid++;
                
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                high--;
                arr[mid]=arr[high];
                arr[high]=2;
                
            }
        }
    }
};