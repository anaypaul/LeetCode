/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
auto speed = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root==0){
            return 0;
        }
        int ans = 0;
        int max_sum = INT_MIN;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            level++;
            int sum = 0;
            for(int i = 0;i<x;i++){
                TreeNode * t = q.front();
                sum += t->val;
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
            if(sum > max_sum){
                max_sum = sum;
                ans = level;
            }
        }
        return ans;
    }
};