class Solution {
  public:
    bool check(vector<int> &arr,int mid,int k){
        int cnt=0;
        for(auto x:arr){
            if(x%mid==0){
                cnt+=(x/mid);
            }
            else{
              cnt+=((x/mid)+1);
            }
            // if(cnt>k)return false;
        }
        return cnt<=k;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low=1;int high=*max_element(arr.begin(),arr.end());int ans=-1;
        while(low<=high){
            int mid=low +(high-low)/2;
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