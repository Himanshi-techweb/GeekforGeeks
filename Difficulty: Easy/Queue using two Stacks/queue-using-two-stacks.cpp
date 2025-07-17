/* The structure of the class is
class StackQueue{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */
void StackQueue::push(int x) {
    if(s1.empty()){
        s1.push(x);
    }
    else{
        while(!s1.empty()){
            s2.push(s1.top());s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());s2.pop();
        }
    }
}

int StackQueue::pop() {
    if(s1.empty() )return -1;
    else{
        int x=s1.top();
        s1.pop();return x; 
    }
}