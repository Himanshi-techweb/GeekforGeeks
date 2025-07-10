// User function template for C++

class Solution {
  public:
    int countltq_x(vector<vector<int>> &mat,int mid){
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            int ub=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
            cnt+=ub;
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();int n=mat[0].size();
        int x=(m*n)/2;int ans=0;
        int low=INT_MAX;int high=INT_MIN;
        for(int i=0;i<m;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][n-1]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=countltq_x(mat,mid);
            if(cnt<x+1){
              ans=mid;
              low=mid+1;  
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
