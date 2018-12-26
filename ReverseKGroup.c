/*
Given a linked list, 
reverse the nodes of a linked list k at a time and 
return its modified list.

k is a positive integer and is less than or equal to the 
length of the linked list. If the number of nodes is not
 a multiple of k then left-out nodes in the end should remain
as it is.

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, 
only nodes itself may be changed.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void printList(struct ListNode *head){
    while(head!=NULL){
        printf("%d->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int l = 0;
    struct ListNode *t = head;
    while(t!=NULL){
        l++;
        t=t->next;
    }
    int no_of_revs = l/k;
    struct ListNode *curr = head;
    struct ListNode *prev = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *dummy = prev;
    prev->val = -1;
    prev->next = curr;
    int i=0;
    while(no_of_revs>0){
        no_of_revs--;
        int group_size = k;
        while(group_size > 1){
            group_size--;
            curr = curr->next;
        }
        struct ListNode *next = curr->next;
        
        // reverse code
        struct ListNode *op_prev = prev;
        struct ListNode *op_curr = prev->next;
        struct ListNode *op_next = NULL;
        while(op_curr != next){
            op_next = op_curr->next;
            op_curr->next = op_prev;
            op_prev = op_curr;
            op_curr = op_next;
        }
        
        //Update the links for the newly reversed portion.
        struct ListNode *t = prev->next;
        prev->next = op_prev;
        t->next = op_curr;
        
        // update curr, prev and next pointers
        prev = t;
        curr = next;
    }
    return dummy->next;
}