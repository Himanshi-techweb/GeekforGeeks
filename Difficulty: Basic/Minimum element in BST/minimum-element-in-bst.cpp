// Function to find the minimum element in the given BST.

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        if(root==NULL)return 0;
        if(!root->left && !root->right)return root->data;
        if(root->left){
            Node* temp=root->left;
            while(temp->left)temp=temp->left;
            return temp->data;
        }
        
        return root->data;
    }
};