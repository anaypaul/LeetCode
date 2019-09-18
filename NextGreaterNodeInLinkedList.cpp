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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        ListNode * curr = head;
        while(curr){
            v.push_back(curr->val);
            curr = curr->next;
        }
        stack<int> st;
        vector<int> res;
        for(int i = v.size()- 1; i>=0;i--){
            if(st.empty()){
                res.push_back(0);
                st.push(v[i]);
            }else{
                if(st.top() > v[i]){
                    res.push_back(st.top());
                    st.push(v[i]);
                }else{
                    while(!(st.empty()) && !(st.top() > v[i]) ){
                        st.pop();
                    }
                    if(!st.empty()){
                        res.push_back(st.top());
                        st.push(v[i]);
                    }else{
                        res.push_back(0);
                        st.push(v[i]);
                    }
                }
            }
        }
        reverse(res.begin(), res.end());
        
        cout<<endl;
        return res;
    }
};