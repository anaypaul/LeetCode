/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> st;
        if(root==NULL){
            return answer;
        }
        st.push(root);
        root=root->left;
        while(!st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            if(!st.empty()){
                TreeNode * t = st.top();
                cout<<t->val<<" "<<endl;;
                answer.push_back(t->val);
                st.pop();
                if(t->right){
                    root = t->right;
                    st.push(t->right);
                    root = root->left;
                }
            }
        }
        return answer;
    }
};