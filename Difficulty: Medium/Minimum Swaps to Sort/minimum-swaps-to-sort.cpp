class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        vector<int> copy=arr;
        unordered_map<int,int> check;
        for(int i=0;i<arr.size();i++){
           check[arr[i]]=i; 
        }
        sort(copy.begin(),copy.end());int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==copy[i])continue;
            else {
               int correctval=copy[i];
               int swapto=check[correctval];
               swap(arr[i],arr[swapto]);
               check[arr[i]]=i;
               check[arr[swapto]]=swapto;
               cnt++;
            }
        }
        return cnt;
    }
};