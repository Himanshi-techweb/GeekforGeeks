class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int high=arr.size()-1;
        int low=-1;
        int curr=0;
        while(curr<=high){
            if(arr[curr]==0){
                low++;
                swap(arr[low],arr[curr]);
                curr++;
            }
            else if(arr[curr]==1)curr++;
            else{
                swap(arr[high],arr[curr]);
                high--;
            }
        }
    }
};