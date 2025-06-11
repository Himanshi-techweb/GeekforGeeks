/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        // Your code here
        stack<Node*> st1;
        vector<int> ans;
        stack<Node*> st2;
        Node* node=root;
        st1.push(root);
        while(!st1.empty()){
            Node* front=st1.top();
            st1.pop();
            st2.push(front);
            if(front->left){
                st1.push(front->left);
            }
            if(front->right){
                st1.push(front->right);
            }
        }
        while(!st2.empty()){
          Node* front=st2.top();
          st2.pop();
          ans.push_back(front->data);
        }
        return ans;
    }
};