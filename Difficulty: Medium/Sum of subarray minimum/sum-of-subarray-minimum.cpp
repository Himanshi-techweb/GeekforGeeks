class Solution {
  public:
    int sumSubarrayMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        const int MOD=1e9 +7;
        // nse calculation
        stack<pair<int,int>> st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && st1.top().first>=arr[i]){
                st1.pop();
            }
            if(!st1.empty())nse[i]=st1.top().second;
            st1.push({arr[i],i});
        }
        // pse calculation
        stack<pair<int,int>> st2;
        for(int i=0;i<n;i++){
            while(!st2.empty() && st2.top().first>arr[i]){
                st2.pop();
            }
            if(!st2.empty())pse[i]=st2.top().second;
            st2.push({arr[i],i});
        }
        //check
        long long ans=0;
        for(int i=0;i<n;i++){
            long long left=(i-pse[i]);
            long long right=(nse[i]-i);
            ans=(ans+((left*right)*arr[i]))%MOD;
        }
        return ans;
    }
};