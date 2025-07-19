

class Solution {
  public:
    bool check(string s1,string s2){
        if(s1.size()==0 && s2.size()==0)return true;
        int i=0;
        while(i<s1.size()-1 && s1[i]==s2[i])i++;
        return s1[i]>s2[i];
    }
    void solve(int i,string s,int k,string &maxi){
        if(i>=s.size() || k==0){
            maxi=max(maxi,s);return;
        }
        maxi=max(maxi,s);
        bool flag=false;
        for(int j=i+1;j<s.size();j++){
          if(s[j]>s[i]){
              flag=true;
              swap(s[j],s[i]);
              solve(i,s,k-1,maxi);
              swap(s[j],s[i]);
          }
        }
        if(!flag){
            solve(i+1,s,k,maxi);
        }
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string maxi=s;
        solve(0,s,k,maxi);
        return maxi ;
        
    }
};