
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &arr) {
        // code here
        vector<int> in(n,1);
        vector<int> de(n,1);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev] && in[i]<1+in[prev]){
                    in[i]=1+in[prev];
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(arr[i]>arr[prev] && de[i]<1+de[prev]){
                    de[i]=1+de[prev];
                }
            }
        }
        int maxi=0;int cnt1=0;int cnt2=0;
        for(int i=0;i<n;i++){
           if(in[i]==1 || de[i]==1)continue;
           maxi=max(maxi,in[i]+de[i]-1); 
        }
        return maxi;
    }
};
