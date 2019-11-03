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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL ||head->next->next == NULL){
            return head;
        }
        ListNode * odd = head;
        ListNode * even = head->next;
        ListNode * evenHead = even;
        while(odd!=NULL && even!=NULL && even->next!= NULL){
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};