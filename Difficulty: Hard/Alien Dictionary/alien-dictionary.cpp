class Solution {
  public:
    
    string findOrder(vector<string> &words) {
        // code here
        vector<int> use(26,0);
        vector<vector<int>> adj(26);
        vector<int>in(26,0);int i=0;
        for(auto word:words){
            for(auto ch:word)use[ch-'a']=1;
        }
        while(i<words.size()-1){
            string text1=words[i];string text2=words[i+1];
            int len=min(text1.size(),text2.size());
            bool flag=false;
            for(int j=0;j<len;j++){
                if(text1[j]!=text2[j]){
                    flag=true;
                    adj[text1[j]-'a'].push_back(text2[j]-'a');
                    in[text2[j]-'a']++;
                    // use[text1[j]-'a']=1;use[text2[j]-'a']=1;
                    break;
                }
            }
            if(!flag && text1.size()>text2.size())return "";
            i++;
        }
        
        ////
        queue<int>q;string ans="";
        for(int i=0;i<26;i++){
            if(use[i] && in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto front=q.front();q.pop();
            ans.push_back(front+'a');
            for(auto it:adj[front]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<use.size();i++){
            if(use[i]==1)cnt++;
        }
        if(cnt>ans.size())return "";
        else return ans;
        
    }
};