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
    void swap(int & a, int & b){
        int t = a;
        a = b;
        b = t;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode(-1);
        ListNode *large = new ListNode(-1);
        ListNode * curr = head;
        ListNode * small_curr = small;
        ListNode * large_curr = large;
        while(curr){
            if(curr->val < x){
                small_curr->next = curr;
                small_curr = small_curr->next;
            }else if(curr->val >= x){
                large_curr->next = curr;
                large_curr = large_curr->next;
            }
            curr = curr->next;
        }
        small_curr ->next = large->next;
        large_curr->next = NULL;
        return small->next;
    }
};