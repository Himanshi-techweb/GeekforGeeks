// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int i=-1;int j=0;
        while(j<arr.size()){
           if(arr[j]!=0){
               break;
           } 
           j++;
        }
        while(j<arr.size()){
            if(arr[j]==0)j++;
            else {
                i++;
                if(i!=j){
                  arr[i]=arr[j];
                  arr[j]=0;  
                }
                j++;
            }
        }
    }
};