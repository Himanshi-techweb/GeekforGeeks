class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int m,n;
        m=mat.size();n=mat[0].size();
        vector<int> arr(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)arr[j]++;
            }
        }
        vector<int> arr1(n,0);
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(mat[i][j]==1)arr1[i]++;
            }
        }
        int ans=-1;
        int cnt=0;
        for(int j=0;j<n;j++){
            
            if(arr[j]==m && arr1[j]==1 ){
                ans=j;
                cnt++;
            }
        }
        
        return (cnt==1)?ans:-1;
    }
};