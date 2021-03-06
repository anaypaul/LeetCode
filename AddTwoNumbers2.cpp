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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode * curr1 = l1;
        ListNode * curr2 = l2;
        ListNode * dummy = new ListNode(-1);
        ListNode * curr = dummy;
        int carry = 0;
        while(curr1!=NULL && curr2!=NULL){
            int x = carry + curr1->val + curr2->val;
            curr->next = new ListNode(x%10);
            carry = x/10;
            curr = curr->next;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1){
            int x = carry + curr1->val ;
            curr->next = new ListNode(x%10);
            carry = x/10;
            curr = curr->next;
            curr1 = curr1->next;
        }
        while(curr2){
            int x = carry + curr2->val;
            curr->next = new ListNode(x%10);
            carry = x/10;
            curr = curr->next;
            curr2 = curr2->next;
        }
        if(carry){
            curr->next= new ListNode(carry);
        }
        curr = dummy;
        dummy = dummy->next;
        
        return reverse(dummy);
    }
};

//Iterative approach without modifying the original linked list
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
    ListNode * reverseList(ListNode * head){
        if(head== NULL || head->next==NULL){
            return head;
        }
        ListNode * rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while(l1){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2 = l2->next;
        }
        ListNode * dummy = new ListNode(-1);
        ListNode * curr = dummy;
        int carry = 0;
        while(!st1.empty() && !st2.empty()){
            int x = (carry + st1.top() + st2.top());
            curr->next = new ListNode(x%10);
            carry = x /10;
            st1.pop();
            st2.pop();
            curr = curr->next;
        }
        while(!st1.empty()){
            int x = (carry + st1.top());
            curr->next = new ListNode(x%10);
            carry = x/10;
            st1.pop();
            curr = curr->next;
        }
        while(!st2.empty()){
            int x= carry + st2.top();
            curr->next = new ListNode(x%10);
            carry = x/10;
            st2.pop();
            curr = curr->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
        }
        curr = dummy->next;
        curr = reverseList(curr);
        return curr;
    }
};