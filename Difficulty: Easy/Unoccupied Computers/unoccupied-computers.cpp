class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int k=0;
        set<char> wait;
        int cnt=0;
        unordered_map<char,int> check;
        for(auto i=0;i<s.size();i++){
           if(check.find(s[i])!=check.end()){
                  check.erase(s[i]);
                   continue;
           }
           else if(wait.find(s[i])!=wait.end())continue;
           else{
               if(check.size()<n){
                   check[s[i]]++;
               }
               else{
                   cnt++;
                   wait.insert(s[i]);
               }
           }
           
        }
        return cnt;
    }
};
