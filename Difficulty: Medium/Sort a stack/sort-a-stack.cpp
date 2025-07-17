/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void insertatbottom(stack<int> &st,int x){
       if(st.empty() || st.top()<=x){
           st.push(x);
           return;
       }
       int y=st.top();    
       st.pop();
       insertatbottom(st,x);
       st.push(y);
}
void SortedStack ::sort() {
    // Your code here
    if(s.empty())return;
    int top=s.top();
    s.pop();
    sort();
    insertatbottom(s,top);
    
}