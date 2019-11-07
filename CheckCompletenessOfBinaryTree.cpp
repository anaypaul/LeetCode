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
    bool checkComplete(TreeNode * root){
        if(root == nullptr){
            return true;
        }
        else if(!root->left && !root->right){
            return true;
        }else if(root->left && !root->right){
            return false;
        }
    }
    bool isCompleteTree(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        queue<TreeNode *> q;
        bool zeroChild = false;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto t = q.front();
                if((t->left == nullptr && t->right!= nullptr) || (zeroChild && (t->left || t->right))){
                    return false;
                }
                if(t->left && t->right){
                    q.push(t->left);
                    q.push(t->right);
                }else{
                    if(t->left){
                        q.push(t->left);
                    }
                    zeroChild = true;
                }
                q.pop();
            }
        }
        return true;
    }
};