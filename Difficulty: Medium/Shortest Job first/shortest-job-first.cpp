class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int cnt=0;int sum=0;
        for(int i=0;i<bt.size()-1;i++){
            sum+=cnt;
            cnt+=bt[i];
            
        }
        sum+=cnt;
        return sum/bt.size();
    }
};