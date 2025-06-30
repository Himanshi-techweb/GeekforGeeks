// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        long long cnt=0;long  sum=0;
        for(int i=0;i<bt.size()-1;i++){
          cnt+=bt[i];
          sum+=cnt;
        }
        return sum/bt.size();
    }
};