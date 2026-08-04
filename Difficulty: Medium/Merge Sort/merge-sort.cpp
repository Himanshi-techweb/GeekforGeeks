class Solution {
  public:
        void merge(int s,int mid,int e,vector<int> &arr){
        //arr1 (s to mid )
        //arr2 (mid+1 to e)
        vector<int> x;
        int i=s;
        int j=mid+1;
        while(i<=mid && j<=e){
            if(arr[i]<=arr[j]){
                x.push_back(arr[i]);
                i++;
            }
            else if(arr[j] <arr[i]){
                x.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            x.push_back(arr[i]);
            i++;
        }
        while(j<=e){
            x.push_back(arr[j]);
            j++;
        }
        j=0;
        for(int i=s;i<=e;i++){
            arr[i]=x[j];
            j++;
        }

    }
    void mergesort(int s,int e,vector<int> &arr){
        if(s==e)return;
        int mid=(s+e)/2;
        mergesort(s,mid,arr);
        mergesort(mid+1,e,arr);
        merge(s,mid,e,arr);
    }
    // vector<int> mergeSort(vector<int>& nums) {\
    //     

    // }
    void mergeSort(vector<int>& nums, int l, int r) {
        // code here
        int e=nums.size()-1;
        mergesort(0,e,nums);
        
        
    }
};