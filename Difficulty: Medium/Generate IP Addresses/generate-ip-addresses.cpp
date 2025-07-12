/*complete the Function*/

class Solution {
    public:
    bool isValid(string x){
        if(x[0]=='0')return false;
        int num=stoi(x);
        if(num>255)return false;
        return true;
    }
    int n;vector<string> result;
    void solve(int i,int part,string s,string curr){
       if(part==4 && i>=n){
           curr.pop_back();
           result.push_back(curr);return;
       }
       //1 length
       if(i+1<=n){
           solve(i+1,part+1,s,curr+s.substr(i,1)+'.');
       }
       if(i+2<=n && isValid(s.substr(i,2))){
           solve(i+2,part+1,s,curr+s.substr(i,2)+'.');
       }
       if(i+3<=n && isValid(s.substr(i,3))){
           solve(i+3,part+1,s,curr+s.substr(i,3)+'.');
       }
    }
    
    vector<string> generateIp(string s) {
        // code here
        n=s.size();
        result.clear();
        string curr="";
        if(s.size()>12)return {};
        solve(0,0,s,curr);
        return result;
    }
};