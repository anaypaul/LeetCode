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
    int helper(TreeNode * root){
        int left_sum = 0;
        int right_sum = 0;
        if(root==NULL){
            return 0;
        }
        TreeNode * curr_left = root->left;
        queue<TreeNode*> q;
        if(root->left){
            q.push(curr_left);
        }
        while(!q.empty()){
            int x = q.size();
            for(int i = 0;i<x;i++){
                TreeNode * t = q.front();
                left_sum += t->val;
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
        }
        TreeNode * curr = root->right;
        if(root->right){
            q.push(root->right);
        }
        while(!q.empty()){
            int x = q.size();
            for(int i = 0;i<x;i++){
                TreeNode * t = q.front();
                right_sum += t->val;
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
        }
        return abs(left_sum - right_sum);
    }
    bool isLeaf(TreeNode * root){
        return !root->left && !root->right;
    }
    int findTilt(TreeNode* root) {
        vector<int> tilt;
        queue<TreeNode * > q;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            int x= q.size();
            for(int i = 0;i<x;i++){
                TreeNode * t = q.front();
                tilt.push_back(helper(t));
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
        }
        return accumulate(tilt.begin(), tilt.end(), 0);
    }
};