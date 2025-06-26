// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &arr) {
        // code here
        bool frow=false;bool fcol=false;
        int m=arr.size();int n=arr[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==0){
                    arr[0][j]=0;
                    arr[i][0]=0;
                    if(i==0)frow=true;
                    if(j==0)fcol=true;
                }
                
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(arr[i][0]==0 || arr[0][j]==0){
                    arr[i][j]=0;
                }
            }
        }
        if(frow){
            for(int j=0;j<n;j++){
                arr[0][j]=0;
            }
        }
        if(fcol){
            for(int i=0;i<m;i++){
                arr[i][0]=0;
            }
        }
    }
};