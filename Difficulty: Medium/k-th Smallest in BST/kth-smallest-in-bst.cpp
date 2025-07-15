/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int ans=-1;
    void small(Node* root,int &count,int k){
        if(root==NULL|| count>k)return;
        small(root->left,count,k);
        count++;
        if(count==k){
            ans=root->data;
            return;
        }
        small(root->right,count,k);
    }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        int count=0;
        small(root,count,k);
        return ans;
    }
};