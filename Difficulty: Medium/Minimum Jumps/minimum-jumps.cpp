class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        if(arr[0]==0)return -1;
        vector<int> check;
        int i=0;int cnt=0;int j=0;
        while(j<arr.size()-1){
          int maxreach=0;
          for(int k=i;k<=j;k++){
              maxreach=max(maxreach,k+arr[k]);
          }
          i=j+1;
          j=maxreach;
          if(i>j)return -1;
          cnt++;
        }
        return cnt;
    }
};
