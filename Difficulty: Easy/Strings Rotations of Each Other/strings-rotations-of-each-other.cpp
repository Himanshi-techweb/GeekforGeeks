
class Solution {
  public:
    vector<int> longestprefixsuffix(string &pattern){
        int size=pattern.size();
        vector<int> lps(size,0);
        lps[0]=0;int i=1;int len=0;
        while(i<size){
            if(pattern[i]==pattern[lps[i-1]]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
        return lps;
    }
    bool kmp(const string &text,string &pattern){
        vector<int> lps=longestprefixsuffix(pattern);
        int i=0;int j=0;
        while(i<text.size()){
            if(text[i]==pattern[j]){
                i++;j++;
                if(j==pattern.size()){
                    // result.push_back(j-i);
                    // j=lps[j-1];
                    return true;
                }
            }
            else if(text[i]!=pattern[j]){
                if(j==0)i++;
                else{
                    j=lps[j-1];
                }
            }
        }
        return false;
    }
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        return kmp(s2+s2,s1);
    }
};