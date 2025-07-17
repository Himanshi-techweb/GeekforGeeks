class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        vector<int>  row;
        int n=mat.size();
        int t=0;int b=n-1;
        while(t<b){
            if(t!=b && mat[t][b]==1)t++; 
            else if(t!=b && mat[b][t]==1)b--;
            else {
                t++;b--;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=t && mat[i][t]==0)return -1;
        }
        for(int j=0;j<n;j++){
            if(j!=t && mat[t][j]==1)return -1;
        }
        return t;
    }
};