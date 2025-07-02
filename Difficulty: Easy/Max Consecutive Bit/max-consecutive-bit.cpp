class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int cnt=1;int maxcnt=0;int prev=arr[0];
        for(int i=1;i<arr.size();i++){
           if(arr[i]!=prev){
               maxcnt=max(maxcnt,cnt);
               cnt=1;
               prev=arr[i];
           }
           else cnt++;
        }
        maxcnt=max(maxcnt,cnt);
        return maxcnt;
    }
};