class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int> check;
        int cnt=0;int l=0;int r=0;int maxlen=0;
        while(l<=r && r<s.size()){
            check[s[r]]++;
            while(check.size()>k){
               check[s[l]]--;
               if(check[s[l]]==0)check.erase(s[l]);
               l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        if(check.size()<k)return -1;
        return maxlen; 
    }
};