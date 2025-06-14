// User function Template for C++

class Solution {
  public:
    bool check(int arr[],int d,int mid,int n){
        int sum=0;int cnt=1;
        for(auto i=0;i<n;i++){
            if(arr[i]>mid)return false;
           if(sum+arr[i]<=mid){
               sum+=arr[i];
           }
           else{
            cnt+=1;
            sum=arr[i];
           }
        }
        //cnt++;
        return cnt<=d;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int high=0;
        for(int i=0;i<n;i++){
            high+=arr[i];
        }
        //int high=*max_element(arr,arr+n);
        //int high=*max_element(arr.begin(),arr.end());
        int low=1;int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(arr,d,mid,n)){
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