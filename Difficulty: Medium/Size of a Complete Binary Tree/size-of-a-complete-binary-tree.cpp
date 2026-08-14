class Solution {
  public:
    int lh(Node* node){
        int h=0;
        while(node){
            h++;
            node=node->left;
        }
        return h;
    }
    int rh(Node* node){
        int h=0;
        while(node){
            node=node->right;
            h++;
        }
        return h;
    }
    int countNodes(Node* root) {
        // code here
        if(root==NULL)return 0;
        int l=lh(root);
        int r=rh(root);
        if(l==r)return (1<<l)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};