class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        // code here
        if(arr.size()==1)return 1;
        int i=0;int j=1;
        while(j<arr.size()){
            if(arr[i]!=arr[j]){
                i++;
                arr[i]=arr[j];
                j++;
            }
            else{
                j++;
            }
        }
        return i+1;
    }
};