class Solution {
  public:
    string findOrder(vector<string> &arr) {
        // code here
        // unordered_map<char,vector<char>>check;
        vector<vector<int>> check(26);
        vector<int> in(26,-1);
        for(int i=1;i<arr.size();i++){
            string text1=arr[i-1];
            string text2=arr[i];
            bool found=false;
            int len=min(text1.length(),text2.length());
            for(int j=0;j<len;j++){
                if(text1[j]!=text2[j]){
                   check[text1[j]-'a'].push_back(text2[j]-'a');
                   if(in[text2[j]-'a']==-1)in[text2[j]-'a']=1;
                   else{in[text2[j]-'a']++;}
                   if(in[text1[j]-'a']==-1)in[text1[j]-'a']=0;
                   found=true;
                   break;
                }
            }
            if(!found && text1.size()>text2.size())return "";
        }
        queue<int> q;
        for(auto x:arr){
            for(auto y:x){
                if(in[y-'a']==-1)in[y-'a']=0;
            }
        }
        for(int i=0;i<in.size();i++){
            if(in[i]==0)q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int front=q.front();q.pop();
            topo.push_back(front);
            for(auto it:check[front]){
                in[it]--;
                if(in[it]==0)q.push(it);
            }
        }
        string ans="";
        for(int i:in){
            if(i>0)return "";
        }
        for(auto x:topo){
            char ch='a'+x;
            ans+=ch;
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};