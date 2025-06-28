class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &arr) {
        // code here
        stack<int> st;
        for(int i=0;i<n;i++){
            if(arr[i]>0)st.push(arr[i]);
            else {
                  while(!st.empty() && st.top()>0 && abs(arr[i])>st.top()){
                   st.pop();
                  }
                  if(!st.empty() && st.top()>0 && st.top()==-arr[i])st.pop();
                  else if(st.empty() || st.top()<0) st.push(arr[i]);
                // }
                // else{
                //     st.push(arr[i]);
                // }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};