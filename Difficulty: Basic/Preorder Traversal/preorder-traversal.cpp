/* A binary tree node has data, pointer to left child
   and a pointer to right child

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:

    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preorder(Node* root) {
        // write code here
        if(root==NULL)return {};
        vector<int> in;
        Node* curr=root;
        while(curr){
            if(!curr->left){
                in.push_back(curr->data);
                curr=curr->right;
            }
            else{
                
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right){
                    curr->left=NULL;
                    curr=curr->right;
                }
                else{
                   in.push_back(curr->data);
                   prev->right=curr;
                   curr=curr->left;
                }
            }
        }
        return in;
    }
};