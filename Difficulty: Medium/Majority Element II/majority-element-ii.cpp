class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int maj1=0;int maj2=0;int cnt1=0;int cnt2=0;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
           if(cnt1==0 && arr[i]!=maj2){
               maj1=arr[i];
           } 
           if(cnt2==0 && arr[i]!=maj1){
               maj2=arr[i];
           }
           if(maj1==arr[i])cnt1++;
           else if(maj2==arr[i])cnt2++;
           else{
               cnt1--;cnt2--;
           }
        }
        if(cnt1!=0 || cnt2!=0){
            cnt1=0;cnt2=0;
            for(int i=0;i<arr.size();i++){
               if(arr[i]==maj1)cnt1++;
               if(arr[i]==maj2)cnt2++;
            }
        }
        if(cnt1>ceil(arr.size()/3) ){
            ans.push_back(maj1);
        }
        if(cnt2>ceil(arr.size()/3) ){
            ans.push_back(maj2);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};