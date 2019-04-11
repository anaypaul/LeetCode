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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * curr = head;
        while(n>0){
            n--;
            curr = curr->next;
        }
        if(curr == NULL){
            return head->next;
        }
        ListNode * curr1 = head;
        while(curr->next!=NULL){
            curr = curr->next;
            curr1 = curr1->next;
        }
        curr1->next = curr1->next->next;
        return head;
    }
};