class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        // code here
        queue<int> st;
        int size=q.size();
        for(int i=0;i<size/2;i++){
            st.push(q.front());q.pop();
        }
        while(!st.empty()){
            q.push(st.front());st.pop();
            q.push(q.front());q.pop();
        }
        return q;
    }
};