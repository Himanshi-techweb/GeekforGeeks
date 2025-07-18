class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
       vector<int> check(26,0);
       long long ans=0;
       for(int i=0;i<s.size();i++){
           check[s[i]-'a']++;
       }
       priority_queue<int> q;
       for(int i=0;i<26;i++){
           if(check[i]>0)q.push(check[i]);
       }
       while(k>0){
           int top=q.top();q.pop();
           top--;
           k--;
           q.push(top);
       }
       while(!q.empty()){
           ans+=(q.top() * q.top());
           q.pop();
       }
       return  ans;
    }
};