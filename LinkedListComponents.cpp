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
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> s;
        for(auto& x : G){
            s.insert(x);
        }
        int ans = 0;
        ListNode * curr = head;
        while(curr){
            if(s.find(curr->val) != s.end() && (curr->next == NULL || s.find(curr->next->val) == s.end())){
                ans++;
            }
            curr = curr->next;
        }
        return ans;
    }
};