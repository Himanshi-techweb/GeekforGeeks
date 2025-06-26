class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int index=-1;
        int m=arr.size();
        for(int i=m-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(arr.begin(),arr.end());
        }
        else{
            for(int i=m-1;i>index;i--){
            if(arr[i]>arr[index]){
                swap(arr[i],arr[index]);
                break;
            }
            }
           reverse(arr.begin()+index+1,arr.end()); 
        }
        
    }
};