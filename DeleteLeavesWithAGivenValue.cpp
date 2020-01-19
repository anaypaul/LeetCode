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
        return root->left == nullptr && root->right == nullptr;
    }
    void deleteNodes(TreeNode * root, int target, TreeNode * parent, int child){
        if(root){
            if(isLeaf(root) && root->val == target){
                if(child == -1){
                    parent->left = parent->right = nullptr;
                }else if(child == 0){
                    parent->left = nullptr;
                }else if(child == 1){
                    parent->right = nullptr;
                }
            }
            deleteNodes(root->left, target, root, 0);
            deleteNodes(root->right, target, root, 1);
        }
    }
    bool check(TreeNode * root, int target){
        if(root){
            if(isLeaf(root) && root->val == target){
                return true;
            }
            return check(root->left, target) || check(root->right, target);
        }
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode * dummy = new TreeNode(-1);   
        dummy->left = dummy->right = root;
        while(check(root, target) && dummy->left && dummy->right){
            int child = -1;
            deleteNodes(root, target, dummy, child);
        }
        return dummy->left;
    }
};