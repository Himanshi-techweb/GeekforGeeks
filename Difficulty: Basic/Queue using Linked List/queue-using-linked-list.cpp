class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {

  public:
    Node* curr;int currsize;Node* f;
    myQueue() {
        // Initialize your data members
        curr= new Node(-1);
        f=NULL;
        currsize=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return currsize==0;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* n=new Node(x);
        if(currsize==0){
            f=n;
            curr=n;
        }
        else {
            curr->next=n;
            curr=curr->next;
        }
        currsize++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(currsize==0)return ;
        Node* t=f;
        f=f->next;
        delete t;
        currsize--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(currsize==0)return -1;
        return f->data;
    }

    int size() {
        // Returns the current size of the queue.
        return currsize;
    }
};
