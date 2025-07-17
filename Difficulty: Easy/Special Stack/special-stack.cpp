#include <vector>
void push(stack<int>& s, int a) {
    // Your code goes here
       vector<int> store;
       while(!s.empty() && s.top()<a){
        store.push_back(s.top());s.pop();
       }
       s.push(a);
       while(store.size()>0){
        s.push(store.back());
        store.pop_back();
       }
}

bool isFull(stack<int>& s, int n) {
    // Your code goes here
    return s.size()==n;
}

bool isEmpty(stack<int>& s) {
    // Your code goes here
    return s.empty();
}

int pop(stack<int>& s) {
    // Your code goes here
    int x=s.top();
    s.pop();return x;
}

int getMin(stack<int>& s) {
    // Your code goes here
    return s.top();
}