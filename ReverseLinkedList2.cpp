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

//my version 
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
    ListNode * reverse(ListNode * head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode * rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    int getLength(ListNode * head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int len = getLength(head);
        if(m==1 && n == len){
            return reverse(head);
        }else if(m==n){
            return head;
        }else{
            if(m==1 && n<=len){
                ListNode * curr = head;
                ListNode * prev = NULL;
                int i;
                for(i = 1;i<n;i++){
                    prev = curr;
                    curr = curr->next;
                }
                ListNode * end = NULL;
                end = curr->next;
                curr->next = NULL;
                head = reverse(head);
                ListNode * temp = head;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = end;
                return head;
                
            }
        }
        ListNode * prev1 = NULL;
        ListNode * curr1 = head;
        int i;
        for(i = 1;i<m;i++){
            prev1 = curr1;
            curr1 = curr1->next;
        }
        ListNode * endOfFirstList = NULL;
        if(prev1){
            endOfFirstList = prev1; 
        }else{
            prev1 = NULL;
        }
        ListNode * temp_head = curr1;
        
        ListNode * prev2 = prev1;
        ListNode * curr2 = curr1;
        for(;i<n;i++){
            prev2 = curr2;
            curr2 = curr2->next;
        }
        
        ListNode * startOfSecondList = curr2->next;
        curr2->next = NULL;
        if(endOfFirstList){
            endOfFirstList->next = NULL;
        }
        temp_head = reverse(temp_head);
        if(endOfFirstList){
            endOfFirstList->next = temp_head;
            ListNode * temp = endOfFirstList;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = startOfSecondList;
            ListNode * tt = startOfSecondList;
            while(tt){
                tt = tt->next;
            }
        }
        return head;
    }
};