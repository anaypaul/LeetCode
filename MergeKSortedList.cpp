//Approach 1
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
//Appraoch 2
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
    ListNode * merge(ListNode * l1, ListNode * l2){
        ListNode * dummy = new ListNode(INT_MIN);
        ListNode * head = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }else{
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
        }
        while(l1){
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        while(l2){
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * res = NULL;
        for(int i = 0; i< lists.size(); i++){
            res = merge(res, lists[i]);
        }
        return res;
    }
};