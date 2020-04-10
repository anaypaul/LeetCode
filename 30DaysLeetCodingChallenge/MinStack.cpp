class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> aux;
    MinStack() {
        
    }
    
    void push(int x) {
        if(st.empty()){
            st.push(x);
            aux.push(x);
        }else{
            st.push(x);
            aux.push(min(aux.top(), x));
        }
    }
    
    void pop() {
        st.pop();
        aux.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return aux.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */