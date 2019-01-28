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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){return NULL;}
        int l1 = 0;
        ListNode *curr1 = headA;
        while(curr1!=NULL){
            curr1 = curr1->next;
            l1++;
        }
        int l2 = 0;
        ListNode *curr2 = headB;
        while(curr2!=NULL){
            curr2 = curr2->next;
            l2++;
        }
        int diff = 0;
        curr1 = headA;
        curr2 = headB;
        if(l1 > l2){
            diff = l1-l2;
            while(diff>0){
                curr1 = curr1->next;
                diff--;
            }
        }else{
            diff = l2-l1;
            while(diff>0){
                curr2 = curr2->next;
                diff--;
            }
        }
        ListNode *ans = NULL;
        int f = 0;
        while(curr1 !=NULL && curr2!=NULL){
            if(curr1==curr2){
                f = 1;
                break;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        if(f==1){
            ans = curr1;
            return ans;
        }else{
            return NULL;
        }
        
    }
};