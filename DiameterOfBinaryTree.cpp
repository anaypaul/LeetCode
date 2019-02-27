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
    int maxi = 0;
    int getDiameter(TreeNode * root){
        if(root == NULL){
            return 0;
        }
        int left = getDiameter(root->left);
        int right = getDiameter(root->right);
        if(left + right > maxi){
            maxi = left+ right ;
        }
        return 1+ max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = getDiameter(root);
        return maxi;
    }
};