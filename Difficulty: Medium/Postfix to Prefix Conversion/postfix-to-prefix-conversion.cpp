// User function Template for C++

class Solution {
  public:
    string postToPre(string arr) {
        // Write your code here
        stack<string> st;
        int i=0;
        int n=arr.size();
        while(i<n){
          char x=arr[i];
          if(isalnum(x)){
              st.push(string(1,x));
          }
          else{
              if(x=='*' || x=='/' || x=='-' || x=='+' || x=='^'){
                  string op1="";string op2="";
                  if(!st.empty()){
                    op1=st.top();
                    st.pop();
                  } 
                  if(!st.empty()){
                    op2=st.top();
                    st.pop();
                  }
                  string y=x+op2+op1;
                  st.push(y);
              }
          }
          i++;
    }
    return st.top();
    }
};