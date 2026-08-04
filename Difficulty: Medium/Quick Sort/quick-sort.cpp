class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high){
            // int pivot=arr[low];
            int index =partition(arr,low,high);
            quickSort(arr,low,index-1);
            quickSort(arr,index+1,high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot=arr[low];
        int i=low;
        int j=high;
        while(i<j){
            while(i<high && arr[i]<=pivot)i++;
            while(j>low && arr[j]>=pivot)j--;
            if(i<j)swap(arr[i],arr[j]);
        }
        swap(arr[low],arr[j]);
        return j;
        
    }
};