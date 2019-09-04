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
    int sum = 0;
    void DFS(TreeNode * root){
        if(root){
            DFS(root->right);
            root->val += sum;
            sum = root->val;
            DFS(root->left);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        DFS(root);
        return root;
    }
};