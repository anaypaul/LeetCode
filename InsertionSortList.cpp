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
    int getLength(ListNode * head){
        int len = 0;
        ListNode * curr = head;
        while(curr){
            curr = curr->next;
            len++;
        }
        return len;
    }
    ListNode* insertionSortList(ListNode* head) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = getLength(head);
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode * dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode * curr = head->next;
        ListNode * prev = head;
        ListNode * next = nullptr;
        head = dummy;
        for(int i = 1; i<n; i++){
            int c = i;
            curr = dummy->next;
            prev = dummy;
            while(c >0){
                c--;
                prev = curr;
                curr = curr->next;
            }
            next = curr->next;
            ListNode * t = head;
            int idx = 0;
            while(t->next!= curr && t->next->val <= curr->val){
                t = t->next;
                idx++;
            }
            if(t->next != curr){
                ListNode * temp = t->next;
                t->next = curr;
                prev->next = curr->next;
                curr->next = temp;
            }
            prev = dummy;
        }
        return dummy->next;
    }
};