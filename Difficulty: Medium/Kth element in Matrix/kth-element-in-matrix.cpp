
class node{
    public:
    int data;int row;int col;
    node(int data,int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }
};

class compare{
    public:
    bool operator()(const node &a, const node &b){
        return a.data>b.data;
    }
};
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        priority_queue<node,vector<node>,compare> q;
        int j=0;
        for(int i=0;i<matrix.size();i++){
            q.push(node(matrix[i][0],i,0));
        }
        while(!q.empty()){
            auto it=q.top();q.pop();
            int col=it.col;int row=it.row;
            j++;
            if(j==k)return it.data;
            else{
                if(col+1<matrix.size())q.push(node(matrix[row][col+1],row,col+1));
            }
        }
        return -1;
    }
};