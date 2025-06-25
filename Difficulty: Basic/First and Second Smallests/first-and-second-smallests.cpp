class Solution {
  public:
  
    void small(int &smallest,int &ssmallest,vector<int> &arr){
        for(int i=0;i<arr.size();i++){
            if(arr[i]<smallest){
                ssmallest=smallest;
                smallest=arr[i];
            }
            else if(arr[i]>smallest && arr[i]<ssmallest){
                ssmallest=arr[i];
            }
        }
    }
    vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
       int smallest=arr[0];
       int ssmallest=INT_MAX;
       small(smallest,ssmallest,arr);
       vector<int> ans(2);
       ans[0]=smallest;
       ans[1]=ssmallest;
       if(ssmallest==INT_MAX)return {-1};
       return ans;
    }
};