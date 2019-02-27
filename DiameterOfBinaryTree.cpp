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
    int Dfs(TreeNode * root , int& result){
        if(root == NULL){
            return 0;
        }
        int left = Dfs(root->left, result);
        int right = Dfs(root->right, result);
        result = max(result, left+right);
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int answer = 0;
        Dfs(root, answer);
        return answer;
    }
};