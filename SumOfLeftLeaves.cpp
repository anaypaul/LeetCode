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
    bool checkLeaf(TreeNode * node){
        return !node->left && !node->right; 
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            for(int i = 0;i<x;i++){
                TreeNode * t = q.front();
                if(t->left){
                    if(checkLeaf(t->left)){
                        cout<<t->left->val<<endl;
                        sum+= t->left->val;
                    }
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
        }
        return sum;
        
    }
};