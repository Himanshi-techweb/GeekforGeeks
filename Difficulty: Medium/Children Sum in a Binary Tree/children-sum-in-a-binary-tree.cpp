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
        if(root->left==NULL && root->right==NULL)return true;
        int left=0;
        if(root->left )left=root->left->data;
        // else if(root->left && root->left->left) left=2*root->left->data;
        int right=0;
        if(root->right )right=root->right->data;
        // else if(root->right && root->right->right) right=2*root->right->data;
        
        bool condi=(root->data==left+right);
        return check(root->left)&& check(root->right) && condi;
    }
    int isSumProperty(Node *root) {
        // Add your code here
        if(!check(root))return false;
        return true;
    }
};