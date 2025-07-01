// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int zero_ix=0;
        while(arr[zero_ix]>0){
            zero_ix++;
        }
        int curr=zero_ix;
        
        
        while(curr<arr.size()){
            if(arr[curr]>0 && curr!=zero_ix){
                swap(arr[curr],arr[zero_ix]);
                zero_ix++;
            }
            curr++;
        }
        
    }
};