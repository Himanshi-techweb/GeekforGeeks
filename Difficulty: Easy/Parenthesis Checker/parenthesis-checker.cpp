
class Solution {
  public:
    bool isBalanced(string& k) {
        // code here
        stack<char> st;
        for(int i=0;i<k.size();i++){
            if((k[i]==')' && !st.empty() && st.top()=='(') || (k[i]==']' && !st.empty() && st.top()=='[') || (k[i]=='}' && !st.empty() && st.top()=='{')){
                st.pop();
            }
            else{
                st.push(k[i]);
            }
        }
        return st.empty();
    }
};