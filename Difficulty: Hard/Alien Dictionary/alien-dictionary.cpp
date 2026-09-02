class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        string str="";
        vector<bool> use(26,0);
        vector<int> in(26,0);
        vector<vector<int>> adj(26);
        for(auto it:words){
            for(auto i:it){
                use[i-'a']=true;
            }
        }
        for(int i=0;i<n-1;i++){
            string str1=words[i];
            string str2=words[i+1];
            int len=min(str1.size(),str2.size());
            int k=0;
            bool flag=false;
            while(k<len ){
                use[str1[k]-'a']=true;
                use[str2[k]-'a']=true;
                if(str1[k]==str2[k])k++;
                else{
                   
                   in[str2[k]-'a']++;
                   flag=true;
                   adj[str1[k]-'a'].push_back(str2[k]-'a');
                   break;
                } 
                
                
            }
            if(flag==false && str2.size()>str1.size()){
                while(k<str2.size()){
                    use[str2[k]-'a']=true;
                    k++;
                }
            }
            else if(flag==false  && str1.size()>str2.size())return "";
        }
        queue<int> q;
        for(int i=0;i<26;i++){
            if(use[i]==true && in[i]==0){
                q.push(i);
            }
        }
        
        
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            char ch=front+'a';
            str.push_back(ch);
            for(auto it:adj[front]){
                in[it]--;
                if(in[it]==0)q.push(it);
            }
        }
        
        for(auto i=0;i<26;i++){
            if(in[i]>0)return "";
        }
        // for(auto it:str)cout<<it<<" ";
        return str;
        
    }
};