class Solution {
  public:
    int solve(int mid,vector<vector<int>>&matrix){
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            cnt+=(lower_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix) {
        // code here
        int m=matrix.size();
        int n=matrix[0].size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            mini=min(mini,matrix[i][0]);
            maxi=max(maxi,matrix[i][n-1]);
        }
        int l=mini;int h=maxi;
        int total=(m*n)/2;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            int count=solve(mid,matrix);
            
            if(count<=total){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
        
    }
};
