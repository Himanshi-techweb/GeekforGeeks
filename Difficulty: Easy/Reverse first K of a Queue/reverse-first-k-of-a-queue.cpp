class Solution {
  public:
    void reversal(queue<int> &q){
        if(q.empty())return;
        int topele=q.front();
        q.pop();
        reversal(q);
        q.push(topele);
    }
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(k>q.size())return q;
        queue<int> qr;
        while(k>0 && !q.empty()){
            qr.push(q.front());q.pop();
            k--;
        }
        reversal(qr);
        while(!q.empty()){
            qr.push(q.front());q.pop();
        }
        return qr;
    }
};