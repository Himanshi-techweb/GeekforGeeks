class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> q;
        q[0]=-1;
        int sum=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(q.find(sum-k)!=q.end()){
                maxi=max(maxi,i-q[sum-k]);
            }
            if(q.find(sum)==q.end())q[sum]=i;
        }
        return maxi;
    }
};