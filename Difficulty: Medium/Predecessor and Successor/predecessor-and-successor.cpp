/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    Node* ans1=NULL;
    Node* ans2=NULL;
    void solve1(Node* root,int key){
        if(root==NULL)return;
        if(root->data<key){
            ans1=root;
            solve1(root->right,key);
        }
        else {
            
            solve1(root->left,key);
           
        }
    }
    
    void solve2(Node* root,int key){
        if(root==NULL)return;
        if(root->data>key){
            ans2=root;
            solve2(root->left,key);
        }
        else solve2(root->right,key);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        solve1(root,key);
        solve2(root,key);
        return {ans1,ans2};
        
    }
};