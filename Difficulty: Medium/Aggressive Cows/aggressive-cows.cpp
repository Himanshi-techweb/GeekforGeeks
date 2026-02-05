class Solution {
  public:
    bool check(int maxi,vector<int> &arr,int k){
       //lets cow initially at arr[0];
       int count=1;
       int prev=arr[0];
       for(int i=1;i<arr.size();i++){
           if(arr[i]-prev>=maxi){
               count++;
               prev=arr[i];
           }
       }
       return count>=k;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int maxi=arr[n-1]-arr[0];
        int low=INT_MAX;
        for(int i=0;i+1<n;i++){
            low=min(low,arr[i+1]-arr[i]);
        }
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,arr,k)){
                maxi=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return maxi;
    }
};


// 1 2 5 7 10