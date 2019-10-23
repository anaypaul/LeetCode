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
    bool isLeaf(TreeNode * root){
        if(!root){
            return false;
        }
        return !root->left && !root->right;
    }
    void getLeaf(TreeNode * root, vector<int> & temp){
        if(root){
            getLeaf(root->left, temp);
            getLeaf(root->right, temp);
            if(isLeaf(root)){
                temp.push_back(root->val);
                return;
            }
        }
    }
    void removeleaf(TreeNode * root){
        if(root){
            if(isLeaf(root->left)){
                root->left = NULL;
            }else{
                removeleaf(root->left);
            }
            if(isLeaf(root->right)){
                root->right = NULL;
            }else{
                removeleaf(root->right);
            }
        }
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while(root){
            vector<int> temp;
            if(isLeaf(root)){
                temp.push_back(root->val);
                root = NULL;
            }
            getLeaf(root, temp);
            res.push_back(temp);
            removeleaf(root);
        }
        return res;
    }
};