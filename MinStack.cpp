/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
#include<stack>
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> aux;
    
    
    MinStack() {
        
    }
    
    void push(int x) {
        if(st.empty() && aux.empty()){
            st.push(x);
            aux.push(x);
        }else{
            if(!aux.empty()){
                int top = aux.top();
                if(x <= top){
                    aux.push(x);
                    st.push(x);
                }else{
                    st.push(x);
                    aux.push(top);
                }
            }
        }
    }
    
    void pop() {
        if(st.empty() || aux.empty()){
            return;
        }else{
            st.pop();
            aux.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top();
        }else{
            return -1;
        }
    }
    
    int getMin() {
        if(!aux.empty() && !st.empty()){
            return aux.top();
        }else{
            return -1;
        }
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */