/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    bool check(Node* root){
        if(root==NULL)return true;
        if(!root->left && !root->right)return true;
        int left=0;int right=0;
        if(root->left)left=root->left->data;if(root->right)right=root->right->data;
        if(root->data!=left+right)return false;
        if(!check(root->left) || !check(root->right))return false;
        
        return true;
    }
    int isSumProperty(Node *root) {
        // Add your code here
        if(!check(root))return false;
        return true;
    }
};