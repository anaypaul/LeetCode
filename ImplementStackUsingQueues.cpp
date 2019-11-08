//Approach 1:
// Push : O(1)
// Pop : O(n)
// top : O(1)
// Empty: O(1)
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> main;
    queue<int> aux;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        main.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int item;
        while(!main.empty()){
            if(main.size()== 1){
                item = main.front();
                break;
            }
            aux.push(main.front());
            main.pop();
        }
        main.pop();
        while(!aux.empty()){
            main.push(aux.front());
            aux.pop();
        }
        return item;
    }
    
    /** Get the top element. */
    int top() {
        return main.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */