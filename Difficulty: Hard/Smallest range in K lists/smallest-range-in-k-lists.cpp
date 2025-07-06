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
    bool operator()(node* a ,node* b){
        return a->data>b->data;
    }
};
class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        int mini=INT_MAX;int maxi=INT_MIN;
        priority_queue<node*,vector<node*>, compare> q;
        for(int i=0;i<arr.size();i++){
           mini=min(mini,arr[i][0]);
           maxi=max(maxi,arr[i][0]);
           q.push(new node(arr[i][0],i,0));
        }
        int x=mini;int y=maxi;
        while(!q.empty()){
            node* front=q.top();q.pop();
            mini=front->data;
            int row=front->row;int col=front->col;
            if(maxi-mini<y-x){
                y=maxi;x=mini;
            }
            if(col+1<arr[0].size() ){
               maxi=max(maxi,arr[row][col+1]);
               q.push(new node(arr[row][col+1],row,col+1));
            }
            else{
               break; 
            }
        }
        vector<int> ans;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};