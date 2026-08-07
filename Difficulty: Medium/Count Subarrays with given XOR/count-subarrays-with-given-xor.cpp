class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> q;
        long ans=0;
        int xor1=0;
        for(int i=0;i<arr.size();i++){
            xor1=xor1^arr[i];
            if(xor1==k)ans++;
            if(q.find(xor1^k)!=q.end())ans+=q[xor1^k];
            q[xor1]++;
            
        }
        return ans;
    }
};