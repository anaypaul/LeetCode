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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next ==NULL){
            return head;
        }
        
        ListNode * remaining = head->next->next;
        ListNode * new_head = head->next;
        new_head->next = head;
        head->next = swapPairs(remaining);
        return new_head;
        
    }
};