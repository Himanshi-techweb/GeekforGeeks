// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        int m=mat[0].size();int max_one=0;int ans=-1;
        //vector<int> check(mat.size());
        for(int i=0;i<mat.size();i++){
            int lb=lower_bound(mat[i].begin(),mat[i].end(),1)-mat[i].begin();
            if(m-lb>max_one){
                max_one=m-lb;
                ans=i;
            }
        }
        return ans;
    }
};