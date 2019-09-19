/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Time complexity : O(n) for traversing the tree. 
//Space complexity : O(n) for storing the nodes in a vector. 
class Solution {
public:
    void inorder(vector<int>& nodes, TreeNode * root){
        if(root){
            inorder(nodes, root->left);
            nodes.push_back(root->val);
            inorder(nodes, root->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(v, root);
        return v[k-1];
    }
};