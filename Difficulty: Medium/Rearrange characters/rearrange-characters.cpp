class node{
   public:
   char ch;int freq;
   node(char ch,int freq){
       this->ch=ch;
       this->freq=freq;
   }
};
class compare{
   public:
   bool operator()(const node&a,const node&b){
       return a.freq<b.freq;
   }
};
class Solution {
  public:
    string rearrangeString(string s) {
        // code here
        unordered_map<char,int> check;
        int maxi=0;
        for(auto it:s){
            check[it]++;
            maxi=max(maxi,check[it]);
        }
        if(maxi>(s.size()/2)+1)return {}; 
        priority_queue<node,vector<node>,compare> q;
        for(auto it:check){
            q.push(node(it.first,it.second));
        }
        string ans="";
        while(!q.empty() ){
            node front=q.top();q.pop();
            auto ch=front.ch;auto freq=front.freq;
            if(ans.empty() || ans.back()!=ch){
                ans=ans+ch;
                freq--;
                if(freq>0)q.push(node(ch,freq));
            }
            else if(!ans.empty() && ans.back()==ch){
                if(!q.empty()){
                   node top=q.top();q.pop();
                   auto ch2=top.ch;auto freq2=top.freq;
                   ans=ans+ch2;
                   freq2--;
                   if(freq2>0)q.push(node(ch2,freq2));
                   if(freq>0)q.push(front);
                }
                else{
                    return "";
                }
            }
        }
        return ans;
    }
};