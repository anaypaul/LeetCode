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
    int idx;
    unordered_map<int, int> m;
    TreeNode * helper(vector<int>& preorder, int low, int high){
        if(low > high){
            return nullptr;
        }
        TreeNode * temp = new TreeNode(preorder[idx++]);
        temp->left = helper(preorder, low, m[temp->val]-1);
        temp->right = helper(preorder, m[temp->val]+1, high);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0){
            return nullptr;
        }
        for(int i = 0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        idx = 0;
        TreeNode * node = new TreeNode(preorder[idx++]);
        node->left = helper(preorder, 0 , m[node->val]-1);
        node->right = helper(preorder, m[node->val] + 1, inorder.size() - 1);
        return node;
    }
};