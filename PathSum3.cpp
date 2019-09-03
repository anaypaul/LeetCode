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
    int answer = 0;
    void DFS(TreeNode * root, int sum){
        if(root == NULL){
            return ;
        }
        if(root->val == sum){
            answer++;
        }
        sum = sum - root->val;
        DFS(root->left, sum);
        DFS(root->right, sum);
        
    }
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return 0;
        }
        DFS(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return answer;
    }
};