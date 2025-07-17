class twoStacks {
  public:
     int n=100;
     int *arr;
     int top1=-1;int top2=n;
    twoStacks() {
        arr=new int[n];
    }
     
    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
       if(top1<top2-1){
           top1++;
           arr[top1]=x;
       }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top1<top2-1){
            top2--;
            arr[top2]=x;
        }
        // code here
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        // code here
        if(top1<=-1){
            return -1;
        }
        int x=arr[top1];
        top1--;
        return x;
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(top2>=n)return -1;
        int x=arr[top2];
        top2++;
        return x;
    }
};