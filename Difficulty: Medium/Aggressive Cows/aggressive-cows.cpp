// User function Template for C++

class Solution {
  public:
    bool check(int mid,vector<int> &arr,int k){
        int cnt=1;int prev=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-prev>=mid){
                cnt++;
                prev=arr[i];
            }
            if(cnt>=k)return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {

        // Write your code here
        sort(arr.begin(),arr.end());
        int low=1;
        int high=arr[arr.size()-1]-arr[0];
        int dist=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,arr,k)){
                dist=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return dist;
    }
};