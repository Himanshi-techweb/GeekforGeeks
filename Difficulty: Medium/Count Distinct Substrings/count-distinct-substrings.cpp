struct Node{
    Node* link[26];
    bool flag=false;
    bool containkey(char ch){
        return link[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        link[ch-'a']=node;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    public:
        Node* root;
        int cnt=0;
        Trie(){
            root=new Node();
        }
        void insert(string str){
            Node* node=root;
            for(int i=0;i<str.size();i++){
                node=root;
                for(int j=i;j<str.size();j++){
                    if(!node->containkey(str[j])){
                        cnt++;
                        node->put(str[j],new Node());
                        
                    }
                    // else break;
                    node=node->get(str[j]);
                }
            }
            node->setEnd();

        }
    
};

class Solution {
  public:
    int countSubs(string& s) {
        // code here
        Trie trie;
        trie.insert(s);
        return trie.cnt;
        
        
    }
};