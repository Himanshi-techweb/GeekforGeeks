// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string begin, string target,
                                         vector<string>& wordList) {
        // code here
      queue<pair<vector<string>,int>>q;
      q.push({{begin},1});
      unordered_set<string> st;
      vector<vector<string>> ans;
      for(auto it:wordList){
          st.insert(it);
      }
      while(!q.empty()){
          int size=q.size();
          unordered_set<string> check;
          for(int i=0;i<size;i++){
            vector<string> front=q.front().first;
            int cnt=q.front().second;
            q.pop();
            string back=front.back();
            if(back==target){
                ans.push_back(front);
            }
            for(int j=0;j<back.size();j++){
                char origi=back[j];
                for(char k='a';k<='z';k++){
                    back[j]=k;
                    if(st.find(back)!=st.end()){
                        check.insert(back);
                        front.push_back(back);
                        q.push({front,cnt+1});
                        front.pop_back();
                    }
                }
                back[j]=origi;
            }
          }
          for(auto it:check){
                st.erase(it);
          }
        //   if(ans.size()>0)break;
      }
      return ans;
    }
};