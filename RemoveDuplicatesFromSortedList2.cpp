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
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode * dummy = new ListNode(INT_MIN);
        dummy->next = head; 
        ListNode * res = NULL;
        ListNode * prev = NULL;
        ListNode * curr = dummy;
        ListNode * temp = NULL;
        ListNode * t_prev = NULL;
        while(curr&&curr->next){
            t_prev = curr;
            temp = curr->next;
            while(temp!= NULL && temp->val == curr->val){
                t_prev = temp;
                temp = temp->next;
            }
            if(curr->next == temp && !res){
                prev = curr;
                curr = temp;
                res = prev;
            }
            else if(curr->next != NULL &&curr->next == temp ){
                prev = curr;
                curr = temp;
            }else{
                if(!res){
                    res = temp;
                    curr = temp; 
                }else{ 
                    prev->next = temp;
                    t_prev->next = NULL;
                    curr = temp;
                }
            }
        }
        return dummy->next;
    }
};