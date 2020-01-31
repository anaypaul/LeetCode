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
    TreeNode * helper(vector<int>& inorder, int ileft, int iright, vector<int>& postorder, int pleft, int pright){
        if(ileft > iright){
            return nullptr;
        }
        TreeNode * root = new TreeNode(postorder[pright]);
        int i = 0;
        for(i = ileft; i<=iright; i++){
            if(root->val == inorder[i]){
                break;
            }
        }
        root->left= helper(inorder, ileft, i-1, postorder, pleft, pleft + i - ileft -1);
        root->right = helper(inorder, i+1, iright, postorder, pleft + i - ileft, pright -1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || inorder.size() != postorder.size()){
            return nullptr;
        }
        TreeNode * root = helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        return root;
    }
    
};