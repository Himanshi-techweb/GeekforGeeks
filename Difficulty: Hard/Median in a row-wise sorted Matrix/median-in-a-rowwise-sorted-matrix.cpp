// User function template for C++

class Solution {
  public:
    bool check(int mid,vector<vector<int>> &mat,int m,int total){
        int cnt=0;
        for(int i=0;i<m;i++){
           auto it=upper_bound(mat[i].begin(),mat[i].end(),mid);
           cnt+=(it-mat[i].begin());
        }
        return cnt<=total/2;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();int n=mat[0].size();
        int mini=INT_MAX;int maxi=INT_MIN;
        int total=m*n;
        for(int i=0;i<m;i++){
            mini=min(mini,mat[i][0]);
        }
        for(int i=0;i<m;i++){
            maxi=max(maxi,mat[i][n-1]);
        }
        int l=mini;int r=maxi;int ans=0;
        while(l<=r){
           int mid=(l+r)/2;
           if(check(mid,mat,m,total)){
               ans=mid;
               l=mid+1; 
           }
           else{
              r=mid-1;
              
           }
        }
        return l;
    }
};
