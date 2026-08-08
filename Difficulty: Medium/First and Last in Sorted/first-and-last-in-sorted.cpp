class Solution {
  public:
    int lower(vector<int>&arr,int x){
        int ans=-1;
        int l=0;int h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==x){
                ans=mid;
                h--;
            }
            else if(arr[mid]<x){
                l++;
            }
            else h--;
            
        }
        return ans;
    }
    int upper(vector<int>&arr,int x){
        int ans=-1;
        int l=0;int h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==x){
                ans=mid;
                l++;
            }
            else if(arr[mid]>x)h--;
            else l++;
        }
        return ans;
        
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int l=lower(arr,x);
        int u=upper(arr,x);
        return {l,u};
        
    }
};