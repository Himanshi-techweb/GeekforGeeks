// User function Template for C++

class Solution {
  public:
    int countPrimes(int L, int R) {
        // code here
        vector<int> prime(R+1);
        for(int i=2;i<=R;i++)prime[i]=1;
        for(int i=2;i*i<=R;i++){
            if(prime[i]==1){
               for(int j=i*i;j<=R;j+=i)prime[j]=0; 
            }
        }int cnt=0;
        for(int i=2;i<=R;i++){
           cnt+=prime[i];
           prime[i]=cnt; 
        }
        return prime[R]-prime[L-1];
    }
};