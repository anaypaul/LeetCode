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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode * res = nullptr;
        if(root == nullptr){
            res = new TreeNode(val);
            return res;
        }
        if(root->val <= val){
            TreeNode * temp = new TreeNode(val);
            temp->left = root;
            root = temp;
        }
        else if(root->val > val){
            root->right = insertIntoMaxTree(root->right, val);
        }
        return root;
    }
};