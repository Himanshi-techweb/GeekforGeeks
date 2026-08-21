class myQueue {

  public:
    int N;
    int s;int e;int currsize=0;int *arr;
    myQueue(int n) {
        // Define Data Structures
        N=n;
        arr=new int[n];
        s=0;e=0;currsize=0;
        
    }

    bool isEmpty() {
        // check if the queue is empty
        return currsize==0;
    }

    bool isFull() {
        // check if the queue is full
        return currsize==N;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull())return;
        arr[e]=(x);
        e=(e+1)%N;
        currsize++;
    }

    void dequeue() {
        if(isEmpty())return;
        // Removes the front element of the queue.
        s=(s+1)%N;
        currsize--;
    }

    int getFront() {
        if(isEmpty())return -1;
        // Returns the front element of the queue.
        return arr[s];
    }

    int getRear() {
        if(isEmpty())return -1;
        // Return the last element of queue
        int r=(e==0)?N-1:e-1;
        return arr[r];
    }
};