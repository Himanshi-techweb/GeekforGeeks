class Solution {
  public:
    bool check(vector<int> &arr,int mid,int k){
        int cnt=0;
        for(auto x:arr){
            cnt+=(ceil((double)x/mid));
        }
        return cnt<=k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(arr,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
