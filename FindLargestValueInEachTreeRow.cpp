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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root== nullptr){
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            int maxVal = INT_MIN;
            for(int i = 0;i<x; i++){
                TreeNode * t = q.front();
                maxVal = max(maxVal , t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
            res.push_back(maxVal);
        }
        
        return res;
    }
};