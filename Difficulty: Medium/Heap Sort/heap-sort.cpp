// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.
void heapify(vector<int> &arr,int n,int i){
    int largest=i;
    int left=2*i +1;
    int right=2*i +2;
    if(left<n && arr[left]>arr[largest])largest=left;
    if(right<n && arr[right]>arr[largest])largest=right;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
class Solution {
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=n/2;i>=0;i--){
            heapify(arr,n,i);
        }
        int size=n;
        while(size>1){
            swap(arr[0],arr[size-1]);
            size--;
            heapify(arr,size,0);
        }
    }
};