/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Time : O(n)
// Space : O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * res = new ListNode(-1);
        ListNode * curr = res;
        while(l1 && l2){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }
        while(l1){
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        while(l2){
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        return res->next;
    }
};