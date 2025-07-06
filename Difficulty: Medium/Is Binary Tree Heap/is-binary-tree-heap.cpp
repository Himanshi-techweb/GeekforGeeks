// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    void totalcnt(Node* root,int &total){
        if(root==NULL)return;
        if(root->left)totalcnt(root->left,total);
        total=total+1;
        if(root->right)totalcnt(root->right,total);
    }
    bool isCBT(Node* root,int i,int total){
        if(root==NULL)return true;
        if(i>=total)return false;
        else{
            return isCBT(root->left,2*i +1,total) && isCBT(root->right,2*i +2 ,total);
        }
    }
    bool maxh(Node* root){
        if(root==NULL)return true;
        if(root->left==NULL && root->right==NULL)return true;
        if(root->left!=NULL && root->left->data>root->data)return false;
        else if(root->right!=NULL && root->right->data>root->data)return false;
        else return maxh(root->left)&& maxh(root->right);
    }
    bool isHeap(Node* root) {
        // code here
        int total=0;
        totalcnt(root,total);
        if(!isCBT(root,0,total) || !maxh(root))return false;
        return true;
    }
};