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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        ListNode * curr = root;
        while(curr){
            len++;
            curr = curr->next;
        }
        vector<ListNode * > res;
        if(len <= k){
            curr = root;
            for(int i = 0;i<k;i++){
                if(curr){
                    res.push_back(curr);
                    curr = curr->next;
                    res[i]->next = NULL;
                }else{
                    res.push_back(NULL);
                }
            }
        }
        else{
            int small_part_size = len/k;
            int x = len - small_part_size * k;
            int bigs = x;
            curr = root;
            for(int i = 0;i<bigs;i++){
                ListNode * temp = curr;
                ListNode * prev = NULL;
                for(int j = 0;j<small_part_size+1; j++){
                    prev = temp;
                    temp=temp->next;
                }
                res.push_back(curr);
                curr = temp;
                prev->next = NULL;
            }
            while(curr){
                ListNode * prev = NULL;
                ListNode * start = curr;
                for(int i = 0;curr && i<small_part_size; i++){
                    prev = curr;
                    curr = curr->next;
                }
                res.push_back(start);
                prev->next = NULL;
            }
        }
        return res;
    }
};