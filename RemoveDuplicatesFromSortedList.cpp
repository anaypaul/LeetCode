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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head== NULL || head->next == NULL){
            return head;
        }
        ListNode * curr = head;
        while(curr->next!= NULL){
            if(curr->val == curr->next->val){
            ListNode * temp = curr->next;
            while(temp && curr->val == temp->val){
                temp = temp->next;
            }
            curr->next= temp;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};