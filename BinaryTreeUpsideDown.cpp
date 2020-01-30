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
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        return parse(root, nullptr, nullptr);
    }
    bool isLeaf(TreeNode * root){
        return !root->left && !root->right;
    }
    TreeNode * parse(TreeNode * curr, TreeNode * parent, TreeNode * sibling){
        if(isLeaf(curr)){
            curr->left = sibling;
            curr->right = parent;
            return curr;
        }
        auto * ret = parse(curr->left, curr, curr->right);
        curr->left = sibling;
        curr->right = parent;
        return ret;
    }
    
};