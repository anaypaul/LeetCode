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
        return root && !root->left && !root->right;
    }
    void getLeaves(TreeNode * root, vector<TreeNode *>& leaves){
        if(root == NULL){
            return;
        }
        if(isLeaf(root)){
            leaves.push_back(root);
        }
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root== NULL){
            return {};
        }
        TreeNode * curr = NULL;
        vector<TreeNode *> left; 
        if(root->left){
            curr = root;
            while(curr){
                left.push_back(curr);
                if(curr->left){
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }
        }else{
            left.push_back(root);
        }
        vector<TreeNode *> leaves;
        getLeaves(root, leaves);
        
        vector<TreeNode *> right;
        curr = root;
        if(curr->right){
            while(curr){
                right.push_back(curr);
                if(curr->right== NULL){
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }
        }else{
            right.push_back(curr);
        }
        unordered_set<TreeNode *> s;
        vector<int> res;
        for(auto x: left){
            if(s.find(x) == s.end()){
                res.push_back(x->val);
                s.insert(x);
            }
        }
        for(auto x: leaves){
            if(s.find(x) == s.end()){
                res.push_back(x->val);
                s.insert(x);
            }
        }
        reverse(right.begin()+1, right.end());
        for(auto x : right){
            if(s.find(x) == s.end()){
                res.push_back(x->val);
                s.insert(x);
            }
        }
        return res;
    }
};