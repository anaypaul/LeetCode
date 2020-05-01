/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode * root){
        if(root != nullptr && root->left == nullptr && root->right == nullptr){
            return true;
        }
        return false;
    }
    void dfs(TreeNode * root,int idx, vector<int> arr, bool & res){
        if(root){
            if(idx == arr.size()-1){
                if(isLeaf(root) && arr[idx] == root->val){
                    res = true;
                }
                return ;
            }else{
                if(root->val == arr[idx]){
                    dfs(root->left, idx + 1, arr, res);
                    dfs(root->right, idx + 1, arr, res);
                }
            }
        }
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        int idx = 0;
        bool res = false;
        dfs(root, 0, arr, res);
        return res;
    }
};