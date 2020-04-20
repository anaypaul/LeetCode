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
    int idx;
public:
    TreeNode * insert(TreeNode * root, int val){
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(root->val > val){
            if(root->left == nullptr){
                root->left = new TreeNode(val);
            }else{
                root->left = insert(root->left, val);
            }
        }else{
            if(root->right == nullptr){
                root->right = new TreeNode(val);
            }else{
                root->right = insert(root->right, val);
            }
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root = nullptr;
        for(int x : preorder){
            root = insert(root, x);
        }
        return root;
    }
};