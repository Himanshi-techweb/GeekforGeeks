class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> st;
        int prefix=0;int len=0;
        for(int i=0;i<arr.size();i++){
            prefix+=arr[i];
            if(prefix==k){
                len=max(len,i+1);
            }
            else {
                if(st.find(prefix-k)!=st.end()){
                    len=max(len,i-st[prefix-k]);
                }
            }
            if(st.find(prefix)==st.end())st[prefix]=i;
        }
        return len;
    }
};