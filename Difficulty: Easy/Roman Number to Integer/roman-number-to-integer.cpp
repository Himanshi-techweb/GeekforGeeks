class Solution {
  public:
    int precedence(char i,char j){
        if(i=='I' && ( j=='V' || j=='X'))return 1;
        if(i=='X' && (j=='L' || j=='C'))return 1;
        if(i=='C' && (j=='D' || j=='M'))return 1;
        return 0;
    }
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char,int> check;
        check['I']=1;check['V']=5;check['X']=10;check['L']=50;
        check['C']=100;check['D']=500;check['M']=1000;
        int ans=0;
        for(int i=0;i<s.size();i++){
           if(i==s.size()-1)ans+=check[s[i]]; 
           else {
               if(precedence(s[i],s[i+1])) {
                   ans-=check[s[i]];
               }
               else{
                  ans+=check[s[i]];
               }
           }
        }
        return ans;
    }
};