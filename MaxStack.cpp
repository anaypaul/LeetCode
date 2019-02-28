#include<stack>

class MaxStack {
public:
    /** initialize your data structure here. */
    stack<int> main_st;
    stack<int> aux_st;
    MaxStack() {
        stack<int> main_st;
        stack<int> aux_st;
    }
    
    void push(int x) {
        if(main_st.empty()){
            main_st.push(x);
            aux_st.push(x);
        }else{
            int m = aux_st.top();
            if(x >= m){
                main_st.push(x);
                aux_st.push(x);
            }else{
                main_st.push(x);
                aux_st.push(m);
            }
        }
    }
    
    int pop() {
        if(!main_st.empty()){
            int x = main_st.top();
            main_st.pop();
            aux_st.pop();
            return x;
        }
        return -1;
    }
    
    int top() {
        if(!main_st.empty()){
            return main_st.top();
        }
        return -1;
    }
    
    int peekMax() {
        if(aux_st.empty()){
            return -1;
        }else{
            return aux_st.top();
        }
    }
    
    int popMax() {
        if(aux_st.empty()){
            return -1;
        }else{
            int x = aux_st.top();
            aux_st.pop();
            stack<int>temp;
            while(main_st.top() != x){
                temp.push(main_st.top());
                main_st.pop();
                aux_st.pop();
            }
            main_st.pop();
            while(!temp.empty()){
                push(temp.top());
                temp.pop();
            }
            return x;
        }
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */