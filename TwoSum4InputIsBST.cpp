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
    void inorder(TreeNode * root, vector<int>& v){
        if(root){
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        unordered_set<int> s;
        for(int i = 0; i<v.size(); i++){
            if(s.find(k - v[i]) != s.end()){
                return true;
            }else{
                s.insert(v[i]);
            }
        }
        return false;
    }
};