class Solution {
  public:
    int wordLadderLength(string start, string target,
                         vector<string>& wordList) {
        // Code here
        unordered_set<string> st;
        for(auto it:wordList){
          st.insert(it);  
        }
        queue<pair<string,int>> q;
        q.push({start,1});
        st.erase(start);
        while(!q.empty() ){
          string text=q.front().first;
          int cnt=q.front().second;
          q.pop();
          if(text==target)return cnt;
          for(int i=0;i<text.size();i++){
            char originalch=text[i];
            for(int j=0;j<26;j++){
              char ch=j+'a';
              text[i]=ch;
              if(st.find(text)!=st.end()){
                  q.push({text,cnt+1});
                  st.erase(text);
              }
            }
            text[i]=originalch;
          }
        }
        return 0;
    }
};