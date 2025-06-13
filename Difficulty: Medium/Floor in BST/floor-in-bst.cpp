// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int input) {
        // Code here
    int f=-1;
    while(root){
        if(root->data==input)return root->data;
        if(root->data>input){
            root=root->left;
        }
        else{
            f=root->data;
            root=root->right;
        }
    }
    return f;
    }
};