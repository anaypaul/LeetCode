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

//Approach 2
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
    int height(TreeNode * root){
        if(root == nullptr){
            return 0;
        }
        int l = height(root->left) + 1;
        int r = height(root->right) + 1;
        return max(l, r);
    }
    void helper(TreeNode * root, int& res){
        if(root == nullptr){
            return ;
        }
        int x= 0;
        if(root->left){
            x = height(root->left) ;
        }
        int y = 0;
        if(root->right){
            y = height(root->right);
        }
        res = max(res, x + y);
        helper(root->left, res);
        helper(root->right, res);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};