class Solution {
  public:
    vector<string> re={};
    string ans="";
    void solve(int i,string &s){
       if(i>=s.size()){
         re.push_back(ans); 
         return; 
       } 
       ans=ans+s[i];
       solve(i+1,s);
       ans.pop_back();
       solve(i+1,s);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        solve(0,s);
        sort(re.begin(),re.end());
        return re;
    }
};