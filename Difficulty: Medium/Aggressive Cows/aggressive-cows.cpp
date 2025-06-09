// User function Template for C++

class Solution {
  public:
    bool ischeck(int mid,int cows,vector<int> &arr){
        int cntcow=1;int last=arr[0];
        for(auto x:arr){
            if(x-last>=mid){
                cntcow++;
                last=x;
            }
            if(cntcow>=cows)return true;
        }return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {

        // Write your code here
        sort(arr.begin(),arr.end());
        int maxi=arr[arr.size()-1]-arr[0];
        int low=1;int high=maxi;int ans=0;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(ischeck(mid,k,arr)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};