/*
Structure of the binary Search Tree is as
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
// your task is to complete the Function
// Function should return median of the BST
int mid1=-1;int mid2=-1;
void check(Node* root,int &count,int total){
    if(root==NULL)return ;
    check(root->left,count,total);
    count++;
    if(count==total/2)mid1=root->data;
    else if(count==(total/2)+1)mid2=root->data;
    check(root->right,count,total);
}
void inorder(Node* root,int &cnt){
    if(root==NULL)return ;
    inorder(root->left,cnt);
    cnt++;
    inorder(root->right,cnt);
}
float findMedian(struct Node *root) {
    // Code here
    int cnt=0;
    inorder(root,cnt);
    int count=0;
    check(root,count,cnt);
    if(cnt%2!=0){
        return mid2;
    }
    else{
        return (mid1+mid2)/2.0;
    }
}