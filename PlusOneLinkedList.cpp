/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //recursive reverse of linked list
    ListNode * reverse(ListNode *head){
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode * rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    ListNode* plusOne(ListNode* head) {
        
        //iterative reverse of linked list
        ListNode * curr = head;
        ListNode * prev = NULL;
        ListNode * next = NULL;
        while(curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr = prev;
        int x = 1;
        int carry = 0;
        ListNode *pp = NULL;
        while(curr!=NULL){
            int t = curr->val + carry + x;
            curr->val = t%10;
            carry = t/10;
            x = 0;
            pp = curr;
            curr = curr->next;
        }
        if(carry){
            pp->next = new ListNode(carry);
            pp->next->next = NULL;
        }
        return reverse(prev);
    }
};