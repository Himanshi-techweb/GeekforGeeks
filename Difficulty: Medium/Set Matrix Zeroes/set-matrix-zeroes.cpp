// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &arr) {
        // code here
        bool f_row=0;bool f_col=0;
        int m=arr.size();int n=arr[0].size();
        for(int i=0;i<m;i++){
            if(arr[i][0]==0)f_col=true;
        }
        for(int i=0;i<n;i++){
            if(arr[0][i]==0)f_row=true;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
               if(arr[i][j]==0){
                   arr[i][0]=0;
                   arr[0][j]=0;
               } 
            }
        }
        for(int i=1;i<m;i++){
            if(arr[i][0]==0){
                for(int j=0;j<n;j++){
                    arr[i][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(arr[0][i]==0){
                for(int j=0;j<m;j++){
                    arr[j][i]=0;
                }
            }
        }
        if(f_col){
            for(int i=0;i<m;i++){
                arr[i][0]=0;
            }
        }
        if(f_row){
            for(int i=0;i<n;i++){
                arr[0][i]=0;
            }
        }
    }
};