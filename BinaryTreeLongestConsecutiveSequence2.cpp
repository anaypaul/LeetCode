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
    pair<int,int> dfs(TreeNode * root, pair<int,int> p, int& ans){
        pair<int,int> res = make_pair(1,1);
        if(root->left){
            pair<int,int> left_temp = make_pair(0,0);
            left_temp = dfs(root->left, left_temp, ans);
            if(root->left->val+1 == root->val){
                res.first = 1 + left_temp.first; 
            }else if(root->left->val -1 == root->val){
                res.second = 1 + left_temp.second;
            }
        }
        if(root->right){
            pair<int,int> right_temp = make_pair(0,0);
            right_temp = dfs(root->right, right_temp, ans);
            if(root->right->val + 1 == root->val){
                res.first = max(res.first , 1 + right_temp.first);
            }else if(root->right->val - 1 == root->val){
                res.second = max(res.second , 1 + right_temp.second);
            }
        }
        ans = max(ans, res.first + res.second - 1);
        
        return res;
    }
    int longestConsecutive(TreeNode* root) {
        if(root == nullptr || (!root->left && !root->right)){
            return root == nullptr ? 0 : 1;
        }
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int res = 0;
        dfs(root, {0, 0}, res);
        return res;
        
    }
};