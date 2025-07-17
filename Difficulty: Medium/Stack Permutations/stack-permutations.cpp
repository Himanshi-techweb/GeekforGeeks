class Solution {
  public:
    bool checkPerm(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> check;
        stack<int> st;int k=0;
        for(int i=0;i<a.size();i++){
            //push into stack
            st.push(a[i]);
            check[a[i]]=1;
            while(!st.empty() && check.find(b[k])!=check.end()){
                if(st.top()==b[k]){
                check.erase(b[k]); 
                k++;
                }
                st.pop();
            }
        }
        return k==b.size();
    }
};