// function Template for C++

class Solution {
  public:
    void insertattop(queue<int> &q,int x){
      q.push(x);
    }
    void reversal(queue<int> &q){
        if(q.empty())return;
        int topele=q.front();
        q.pop();
        reversal(q);
        insertattop(q,topele);
    }
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        reversal(q);
        return q;
    }
};