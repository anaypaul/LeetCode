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
    int getLen(ListNode * head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        int len = getLen(head);
        k = k %len;
        if( k == 0){
            return head;
        }
        ListNode * curr = head;
        for(int i = 0; i<len-k-1; i++){
            curr = curr->next;
        }
        ListNode * new_head = curr->next;
        curr->next = NULL;
        curr=new_head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = head;
        return new_head;
    }
};