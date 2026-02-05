class Solution {
  public:
    bool check(int j,vector<int>&arr,int k){
        int count=0;int sum=0;
        for(int i=0;i<arr.size();i++){
           if(sum+arr[i]>j){
               count++;
               sum=arr[i];
           }
           else sum=sum+arr[i];
        }
        count++;
        // cout<<count<<" "<<j<<endl;
        return count<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k)return -1;
        int low=*max_element(arr.begin(),arr.end());
        // int low=0;

        int high=accumulate(arr.begin(),arr.end(),0);
        // cout<<low<<" "<<high<<" ";
        int maxi=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,arr,k)){
                maxi=mid;
                high=mid-1;
              
            }
            else 
            low=mid+1;
        }
        return maxi;
    }
};