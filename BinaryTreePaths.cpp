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
        if(root==NULL){
            return false;
        }
        if(!root->left && !root->right){
            return true;
        }
        return false;
    }
    void dfs(TreeNode * root, string s, vector<string>& v){
        if(isLeaf(root)){
            if(s.length() == 0){
                s = s + to_string(root->val);
            }else{
                s = s + "->" + to_string(root->val);
            }
            v.push_back(s);
        }
        if(s.length()== 0){
            s = s + to_string(root->val);
        }else{
            s = s + "->" + to_string(root->val);
        }
        if(root->left){
            dfs(root->left, s, v);
        }
        if(root->right){
            dfs(root->right, s, v);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root == NULL){
            return v;
        }
        
        dfs(root, "", v);
        return v;
    }
};