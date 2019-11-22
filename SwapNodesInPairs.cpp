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
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(head == nullptr){
            return head;
        }
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * prev = dummy;
        ListNode * curr = head;
        ListNode * next = nullptr;
        while(curr!= nullptr && curr->next != nullptr){
            next = curr->next->next;
            prev->next = curr->next;
            curr->next = next;
            prev->next->next = curr;
            prev = curr;
            curr = next;
        }
        return dummy->next;
    }
};