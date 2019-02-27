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

    void flatten(TreeNode* root) {
        //iterative solution
        while(root){
            if(root->left){
                TreeNode * pre = root->left;
                while(pre->right){
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
    void flatten(TreeNode* root) {
        //recursive solution
        if(root){
            if(root->left){
                TreeNode * next = root->right;
                root->right = root->left;
                flatten(root->right);
                TreeNode *t = root->right;
                while(t->right!=NULL){
                    t = t->right;
                }
                flatten(next);
                t->right = next;
                root->left = NULL;
            }else if(root->right){
                TreeNode *t = root;
                while(t->left==NULL && t->right !=NULL){
                    t = t->right;
                }
                flatten(t);
            }
        }
    }
};