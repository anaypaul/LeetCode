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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int num = 0;
        ListNode *answer = new ListNode(-1);
        ListNode *res= answer;
        while(l1!=NULL && l2!=NULL){
            num = l1->val + l2->val + carry;
            carry = num/10;
            num = num%10;
            res->next = new ListNode(num);
            l1 = l1->next;
            l2 = l2->next;
            res = res->next;
        }
        while(l1!=NULL){
            num = l1->val + carry;
            carry = num/10;
            num = num %10;
            res->next = new ListNode(num);
            l1 = l1->next;
            res = res->next;
        }
        while(l2!=NULL){
            num = l2->val + carry;
            carry = num/10;
            num = num %10;
            res->next = new ListNode(num);
            l2 = l2->next;
            res = res->next;
        }
        if(carry != 0){
            res->next = new ListNode(carry);
        }
        return answer->next;
    }
};
