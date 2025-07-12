class Solution {
  public:
    int findSubString(string& str) {
        // code here
        set<char> st;
        for(auto it:str)st.insert(it);
        int dist=st.size();
        int unique=0;
        int cnt=INT_MAX;int l=0;int h=0;
        unordered_map<char,int> freq;
        for(;h<str.size();){
            freq[str[h]]++;
            if(freq[str[h]]==1)unique++;
            h++;
            while(unique==dist){
                cnt=min(cnt,h-l);
                freq[str[l]]--;
                if(freq[str[l]]==0)unique--;
                l++;
            }
        }
        return cnt;
    }
};