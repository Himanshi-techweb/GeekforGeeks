class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> st;
        int cnt=0;int maxcnt=1;
        for(auto it:arr){
            st.insert(it);
        }
        for(int i=0;i<arr.size();i++){
            int x=arr[i];
            if(st.find(x-1)!=st.end())continue;
            else{
              int cnt=0;
              while(st.find(x)!=st.end()){
                  st.erase(x);
                  x=x+1;
                  cnt++;
              }
              maxcnt=max(maxcnt,cnt);
            }
        }
        return maxcnt;
    }
};