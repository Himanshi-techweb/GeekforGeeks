class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int> check(26,0);
        int l=0;int r=0;
        int maxlen=0;
        while(l<=r && r<s.size()){
           check[s[r]-'a']++;
           while(check[s[r]-'a']>1){
              check[s[l]-'a']--;
              l++;
           }
           maxlen=max(maxlen,r-l+1);
           r++;
        }
        return maxlen;
    }
};
