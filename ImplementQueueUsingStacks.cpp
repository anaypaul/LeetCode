class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st;
    stack<int> aux;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int item;
        while(!st.empty()){
            aux.push(st.top());
            st.pop();
        }
        item = aux.top();
        aux.pop();
        while(!aux.empty()){
            st.push(aux.top());
            aux.pop();
        }
        return item;
    }
    
    /** Get the front element. */
    int peek() {
        int item; 
        while(!st.empty()){
            aux.push(st.top());
            st.pop();
        }
        item = aux.top();
        while(!aux.empty()){
            st.push(aux.top());
            aux.pop();
        }
        return item;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */