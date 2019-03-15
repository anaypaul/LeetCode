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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }else{
            if(root->left && root->right){
                int l = minDepth(root->left);
                int r = minDepth(root->right);
                return min(l,r) + 1;
            }else{
                if(root->left){
                    return minDepth(root->left) + 1;
                }
                else{
                    return minDepth(root->right) + 1;
                }
            }
        }
    }
};