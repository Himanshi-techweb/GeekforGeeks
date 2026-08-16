/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node* f=NULL;
    Node* s=NULL;
    Node* m=NULL;
    vector<Node*> in;
    void inorder(Node* root){
        if(root==NULL)return;
        inorder(root->left);
        in.push_back(root);
        inorder(root->right);
    }
    Node* correctBST(Node* root) {
        // code here
        inorder(root);
        for(int i=0;i<in.size()-1;i++){
            if(in[i]->data>in[i+1]->data){
                if(f==NULL){
                    f=in[i];
                    m=in[i+1];
                }
                else s=in[i+1];
            }
        }
        if(s==NULL){
            int curr=m->data;
            m->data=f->data;
            f->data=curr;
            return root;
        }
        int curr=s->data;
        s->data=f->data;
        f->data=curr;
        return root;
    }
};