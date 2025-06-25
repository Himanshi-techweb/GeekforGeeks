class Solution {
  public:
    int maxConsecutiveCount(vector<int> &arr) {
        // code here
        int i=0;int j=0;
        int maxi=0;
        while(j<arr.size()){
            if(arr[i]==arr[j]){
                if(j==arr.size()-1){
                  maxi=max(maxi,(j-i+1));  
                }
                j++;
            }
            else if(arr[i]!=arr[j] ){
                maxi=max(maxi,(j-i));
                i=j;
            }
        }
        return maxi;
    }
};