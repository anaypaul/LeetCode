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
    ListNode* reverse(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        } 
        ListNode * rest = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        ListNode * curr = head;
        int res = 0;
        int idx = 0;
        while(curr){
            res += (curr->val) * pow(2, idx);
            idx++;
            curr = curr->next;
            
        }
        return res;
    }
};