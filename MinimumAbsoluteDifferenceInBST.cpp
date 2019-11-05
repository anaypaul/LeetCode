/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> res;
class Solution {
public:
    void dfs(TreeNode * root){
        if(root){
            dfs(root->left);
            res.push_back(root->val);
            dfs(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        dfs(root);
        for(int i = 0; i<res.size()-1; i++){
            diff = min(diff, abs(res[i] - res[i+1]));
        }
        res.clear();
        return diff;
    }
};