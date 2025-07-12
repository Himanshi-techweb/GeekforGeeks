class Solution {
  public:
    int minimumNumberOfSwaps(string& s) {
        // code here
        int cnt=0;
        stack<char> st;
        for(int i=0;i<s.size();){
           if(s[i]=='['){
               st.push(s[i]);i++;
           }
           else if(s[i]==']' && !st.empty()){
               st.pop();i++;
           }
           else if(s[i]==']' && st.empty()){
               int k=i;
               while(k<s.size() && s[k]!='[')k++;
               while(k>i){
                   swap(s[k],s[k-1]);k--;cnt++;
               }
           }
        }
        return cnt;
    }
};