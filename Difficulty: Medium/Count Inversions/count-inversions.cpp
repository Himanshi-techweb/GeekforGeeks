class Solution {
  public:
    int cnt=0;
    void merge(int low,int mid,int high,vector<int>&arr){
        //a is low to mid
        //b is mid+1 to high
        vector<int> ans;
        int i=low;int j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i]>arr[j]){
                cnt+=(mid-i+1);
                j++;
            }
            else i++;
        }
        i=low;j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i]<arr[j]){
                ans.push_back(arr[i]);
                i++;
            }
            else{
                ans.push_back(arr[j]);
                j++;
            }
            
        }
        while(i<=mid){
            ans.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            ans.push_back(arr[j]);
            j++;
        }
        int k=0;
        for(int i=low;i<=high;i++){
            arr[i]=ans[k++];
        }
    }
    void mergesort(int low,int high,vector<int> &arr){
        if(low<high){
            int mid=(low+high)/2;
            mergesort(low,mid,arr);
            mergesort(mid+1,high,arr);
            merge(low,mid,high,arr);
        }
    }
    int inversionCount(vector<int> &arr) {
        // code here
        mergesort(0,arr.size()-1,arr);
        return cnt;
    }
};