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
    int closestValue(TreeNode* root, double target) {
        vector<int> v;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                TreeNode * t = q.front();
                v.push_back(t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
        }
        double res = v[0];
        double mindiff = abs(v[0] - target);
        for(int i = 1; i<v.size(); i++){
            if(mindiff > abs((double)v[i] - target) ){
                mindiff = abs((double)v[i] - target);
                res = v[i];
            }
        }
        return res;
    }
};