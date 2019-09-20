/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node * curr = head;
        while(curr){
            Node * temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
            temp->random = NULL;
        }
        
        curr = head;
        while(curr ){
            curr->next->random = curr->random != NULL ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        curr = head;
        Node * curr_new = head->next;
        Node * result = head->next;
        while(curr!= NULL){
            curr->next = curr->next->next;
            curr_new->next = curr_new->next != NULL ? curr_new->next->next : NULL;
            curr = curr->next;
            curr_new = curr_new->next;
        }
        return result;
        
    }
};