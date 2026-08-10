class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        vector<int> cnt(n,0);
        for(int i=0;i<n;i++){
            int x=lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
            cnt[i]=m-x;
        }
        int max=0;
        int max_i=-1;
        for(int i=0;i<n;i++){
            if(cnt[i]>max && cnt[i]>0){
                max_i=i;
                max=cnt[i];
            }
        }
        return max_i;
    }
};