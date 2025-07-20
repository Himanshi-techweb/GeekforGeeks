class Solution {
  public:
    void nextPermutation(vector<int> &arr) {
        int n=arr.size();
        int k=-1;
        for(int i=n-2;i>=0;){
          if(arr[i]<arr[i+1]){
            k=i;break;  
          } 
          i--;
        }
        if(k==-1){
            reverse(arr.begin(),arr.end());
        }
        else{
            for(int i=n-1;i>k;i--){
                if(arr[i]>arr[k]){
                    swap(arr[k],arr[i]);
                    break;
                }
            }
            reverse(arr.begin()+k+1,arr.end());
        }
    }
};