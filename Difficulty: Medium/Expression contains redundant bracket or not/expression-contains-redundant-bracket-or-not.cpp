class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=')')st.push(s[i]);
            else{
                if(st.top()=='(')return true;
                int cnt=0;
                while(!st.empty() && st.top()!='('){
                    if(!isalpha(st.top()))cnt++;
                    st.pop();
                }
                st.pop();
                if(cnt==0)return true;
            }
        }
        return false;
    }
};
