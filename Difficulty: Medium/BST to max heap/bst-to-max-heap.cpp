// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
    void preorder(Node* root,vector<int> &in,int &i){
        if(root==NULL) return;
        preorder(root->left,in,i);
        preorder(root->right,in,i);
        root->data=in[i++];
    }
    void inorder(vector<int> &in,Node* root){
        if(root==NULL)return ;
        inorder(in,root->left);
        in.push_back(root->data);
        inorder(in,root->right);
    }
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int> in;
        inorder(in,root);
        int i=0;
        preorder(root,in,i);
    }
};
