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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL){
            return head;
        }
        
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(m>1){
            prev = curr;
            curr = curr->next;
            m--;
            n--;
        }
        
        ListNode * tail = curr;
        ListNode * con = prev;
        ListNode * temp=NULL;
        while(n>0){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            n--;
        }
        if(con!=NULL){
            con->next = prev;
        }else{
            head = prev;
        }
        tail->next = curr;
        return head;
    }
};