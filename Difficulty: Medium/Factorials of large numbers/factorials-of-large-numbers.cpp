// User function template for C++

class Solution {
  public:
    void carry(int multiplier,vector<int> &arr,int &size){
       int carry=0;
       for(int i=0;i<size;i++){
           int quot=arr[i]*multiplier;
           quot=quot+carry;
           arr[i]=quot%10;
           carry=quot/10;
       }
       while(carry>0){
           arr[size]=carry%10;
           size++;
           carry=carry/10;
       }
        
    }
    vector<int> factorial(int n) {
        // code here
        vector<int> arr(1e6,0);
        arr[0]=1;
        int size=1;
        for(int i=2;i<n+1;i++){
            carry(i,arr,size);
        }
        vector<int> ans;
        for(int i=size-1;i>=0;i--){
            ans.push_back(arr[i]);
        }
        return ans;
        
        
    }
};