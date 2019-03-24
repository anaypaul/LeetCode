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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode *curr = head;
        while(curr){
            len++;
            curr = curr->next;
        }
        curr = head;
        ListNode * fast = head;
        if(len%2==1){
            while(fast!= NULL && fast->next!= NULL){
                fast = fast->next->next;
                curr = curr->next;
            }
        }else{
            while(fast!=NULL && fast->next!= NULL){
                fast = fast->next->next;
                curr = curr->next;
            }
        }
        return curr;
    }
};