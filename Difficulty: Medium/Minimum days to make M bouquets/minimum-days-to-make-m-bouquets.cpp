class Solution {
  public:
     bool check(vector<int> &arr,int mid,int m,int k){
         int cnt=0;int sum=0;
         for(auto x:arr){
             if(mid>=x){
                sum++; 
             }
             else{
                cnt+=(sum/k);
                sum=0;
             }
         }
         if(sum!=0){
           cnt+=(sum/k);  
         }
         return cnt>=m;
     }
    int minDaysBloom(int m, int k, vector<int> &arr) {
        // Code here
        int high=*max_element(arr.begin(),arr.end());
        int low=*min_element(arr.begin(),arr.end());
        int ans=-1;
        while(low<=high){
            int mid =low +(high-low)/2;
            if(check(arr,mid,m,k)){
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