class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int size=arr.size();
        for(int i=0;i<size/2;i++){
            int j=arr[size-i-1];
            arr[size-i-1]=arr[i];
            arr[i]=j;
            
        }
    }
};