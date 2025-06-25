class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int cnt0=0;int cnt1=0;int cnt2=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)cnt0++;
            if(arr[i]==1)cnt1++;
            if(arr[i]==2)cnt2++;
        }int i=0;int k=0;
        while(i<arr.size() && k<cnt0){
            arr[i]=0;
            k++;
            i++;
        }k=0;
        while(i<arr.size() && k<cnt1){
            arr[i]=1;
            k++;
            i++;
        }k=0;
        while(i<arr.size() && k<cnt2){
            arr[i]=2;
            k++;
            i++;
        }
    }
};