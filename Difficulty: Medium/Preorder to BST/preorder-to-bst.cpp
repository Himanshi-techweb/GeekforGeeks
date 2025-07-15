// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    Node* build(int in[],int pre[],int &i,int size,int st,int end,unordered_map<int,int> check){
        if(i>=size || st>end)return NULL;
        Node* root=newNode(pre[i]);
        int ix=check[pre[i++]];
        root->left=build(in,pre,i,size,st,ix-1,check);
        root->right=build(in,pre,i,size,ix+1,end,check);
        return root;
    }
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        int in[size];
        copy(pre,pre+size,in);
        unordered_map<int,int> check;
        sort(in,in+size);
        for(int i=0;i<size;i++){
            check[in[i]]=i;
        }
        int i=0;
        return build(in,pre,i,size,0,size-1,check);
    }
};