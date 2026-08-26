class Solution {
  public:
    vector<string> powerSet(string &s) {
        // Code here
        int n=s.size();
        vector<string> ans;
        for(int bit=0;bit<(1<<n);bit++){
            string str="";
            for(int i=0;i<n;i++){
                int x=bit;
                x=x>>i;
                if(x&1==1)str+=s[i];
                
            }
            ans.push_back(str);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};