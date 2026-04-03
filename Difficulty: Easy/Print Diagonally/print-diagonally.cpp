class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        vector<int> ans;
        int m=mat.size();
        //first row
        for(int j=0;j<m;j++){
            //i should increase from 0 till i==j
            int i=0;int k=j;
            while(i<=j && k>=0){
                ans.push_back(mat[i][k]);
                i++;k--;
            }
        }
        
        //then all row from row 2 
        
        for(int i=1;i<m;i++){
           int k=i;int j=m-1;
           while(k<=m-1 && j>=i){
               ans.push_back(mat[k][j]);
               k++;j--;
           }
        }
        return ans;
    }
};