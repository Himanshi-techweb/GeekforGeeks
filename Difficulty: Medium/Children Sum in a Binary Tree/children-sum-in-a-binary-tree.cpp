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
        if(root==NULL || (root->left==NULL && root->right==NULL))return true;
        int left=(root->left) ? root->left->data:0;
        int right=(root->right) ? root->right->data:0;
        bool condition =(root->data==left+right);
        return condition && check(root->left) && check(root->right);
    }
    int isSumProperty(Node *root) {
        // Add your code here
        return check(root);
    }
};