class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int l=0;
        int r=0;
        int cnt=0;
        while(r<arr.size()-1){
            int farthest=r;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,arr[i]+i);
            }
            if(farthest==r)return -1;
            cnt++;
            l=r+1;
            r=farthest;
        }
        return cnt;
    }
};
