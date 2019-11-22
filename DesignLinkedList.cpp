class Node{
    public:
    int data;
    Node *next;
    Node(int val): data{val}, next{nullptr} {
        
    }
};
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    unsigned int size;
    Node * head;
    MyLinkedList() {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        head = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(size == 0 || index >= size || index < 0){
            return -1;
        }
        Node * curr = head;
        while(index--){
            curr = curr->next;
        }
        return curr->data;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        size++;
        Node * t = new Node(val);
        t->next = head;
        head = t;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(head== nullptr){
            head = new Node(val);
        }
        Node * curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = new Node(val);
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(size == index){
            addAtTail(val);
            return;
        }
        if(index > size){
            return ;
        }
        if(index == 0){
            addAtHead(val);
            return ;
        }
        Node * curr = head;
        while(index-1>0){
            curr = curr->next;
            index--;
        }
        Node * t = new Node(val);
        size++;
        t->next = curr->next;
        curr->next = t;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size){
            return ;
        }
        if(index == 0){
            head = head ->next;
            size--;
            return;
        }
        Node * curr = head;
        while(index-1>0){
            curr = curr->next;
            index--;
        }
        curr->next =curr->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */