class Solution {
  public:
    long long subarrayRanges(vector<int>& arr) {
        // code here
        int n=arr.size();
        //sum of subarray minimum 
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
        long long mini=0;
        for(int i=0;i<n;i++){
            long long left=(i-pse[i]);
            long long right=(nse[i]-i);
            mini=(mini+((left*right)*arr[i]));
        }
        
        //sum of subarray maximum
        vector<int> pge(n,-1);
        vector<int> nge(n,n);
        // nse calculation
        stack<pair<int,int>> st3;
        for(int i=n-1;i>=0;i--){
            while(!st3.empty() && st3.top().first<=arr[i]){
                st3.pop();
            }
            if(!st3.empty())nge[i]=st3.top().second;
            st3.push({arr[i],i});
        }
        // pse calculation
        stack<pair<int,int>> st4;
        for(int i=0;i<n;i++){
            while(!st4.empty() && st4.top().first<arr[i]){
                st4.pop();
            }
            if(!st4.empty())pge[i]=st4.top().second;
            st4.push({arr[i],i});
        }
        //check
        long long maxi=0;
        for(int i=0;i<n;i++){
            long long left=(i-pge[i]);
            long long right=(nge[i]-i);
            maxi=(maxi+((left*right)*arr[i]));
        }
        return maxi-mini;
    }
};