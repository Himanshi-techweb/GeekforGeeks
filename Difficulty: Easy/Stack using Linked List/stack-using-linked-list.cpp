/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class myStack {

  public:
    Node* front;int currsize;
    myStack() {
        // Initialize your data membersz
        currsize=0;
        front=NULL;
    }

    bool isEmpty() {
        // check if the stack is empty
        return currsize==0;
    }

    void push(int x) {
        // Adds an element x at the front of the stack
        Node* node=new Node(x);
        node->next=front;
        front=node;
        currsize++;
    }

    void pop() {
        // Removes the front element of the stack
        if(currsize==0)return;
        Node* t=front;
        front=front->next;
        delete t;
        currsize--;
        
    }

    int peek() {
        // Returns the front element of the stack
        // If stack is empty, return -1
        if(isEmpty())return -1;
        return front->data;
    }

    int size() {
        // Returns the current size of the stack
        return currsize;
    }
};