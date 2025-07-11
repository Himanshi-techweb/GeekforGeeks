class Solution {
  public:
    bool solve(int i,int j,int k,string &s1,string &s2,string&s3){
        if(i>=s1.size() && j>=s2.size() && k>=s3.size())return true;
        if(k>=s3.size() && i<s1.size())return false;
        if(k>=s3.size() && j<s2.size())return false;
        if(s1[i]!=s3[k] && s2[j]!=s3[k])return false;
        if(s1[i]==s3[k] && s2[j]!=s3[k]){
            return solve(i+1,j,k+1,s1,s2,s3);
        }
        else if(s2[j]==s3[k] && s1[i]!=s3[k]){
            return solve(i,j+1,k+1,s1,s2,s3);
        }
        else {
            return (solve(i+1,j,k+1,s1,s2,s3) || solve(i,j+1,k+1,s1,s2,s3));
        }
    }
    bool isInterleave(string& s1, string& s2, string& s3) {
        // code here
        return solve(0,0,0,s1,s2,s3);
    }
};