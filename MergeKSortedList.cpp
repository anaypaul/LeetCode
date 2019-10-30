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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        priority_queue<int, vector<int> , greater<int>> q;
        for(auto head : lists){
            while(head){
                q.push(head->val);
                head = head->next;
            }
        }
        ListNode * dummy = new ListNode(INT_MIN);
        ListNode * curr = dummy;
        while(!q.empty()){
            curr->next = new ListNode(q.top());
            curr = curr->next;
            q.pop();
        }
        return dummy->next;
    }
};