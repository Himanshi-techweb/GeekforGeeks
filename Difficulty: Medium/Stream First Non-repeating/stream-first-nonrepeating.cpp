class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        vector<int> check(26,0);
        queue<char> q;
        string ans="";
        for(int i=0;i<s.size();i++){
            check[s[i]-'a']++;
            if(check[s[i]-'a']==1){
               q.push(s[i]);
            }
            while( !q.empty() && check[q.front()-'a']>1){
                q.pop();
            }
            if(q.empty())ans+='#';
            else{
              ans+=q.front();  
            }
            
        }
        return ans;
    }
};