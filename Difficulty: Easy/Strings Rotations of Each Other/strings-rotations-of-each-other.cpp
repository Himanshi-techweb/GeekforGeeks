class Solution {
  public:
    vector<int> longestcommonprefixsuffix(string &pattern){
      vector<int> lps(pattern.size(),0);
      lps[0]=0;int len=0;
      for(int i=1;i<pattern.size();){
          if(pattern[i]==pattern[len]){
              len++;
              lps[i]=len;
              i++;
          }
          else{
              if(len==0){
                  lps[i]=0;i++;
              }
              else{
                  len=lps[len-1];
              }
          }
      }
      return lps;
    }
    bool kmp(string &pattern,string &text){
        vector<int> lps=longestcommonprefixsuffix(pattern);
        int j=0;
        for(int i=0;i<text.size();){
            if(pattern[j]==text[i]){
                i++;j++;
                if(j==pattern.size())return true;
            }
            else{
                if(j==0)i++;
                else{
                    j=lps[j-1];
                }
            }
        }
        return false;
    }
    bool areRotations(string &s1, string &s2) {
        // code here
        string s3=s1;
        s3=s3+s1;
        return kmp(s2,s3);
    }
};