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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL){
            return 0;
        }else{ 
            int left = rangeSumBST(root->left, L,R);
            int right = rangeSumBST(root->right, L,R);
            if( root->val >= L and root->val <=R ){
                return root->val + left + right;
            }else{
                return left + right;
            }
        }
    }
};