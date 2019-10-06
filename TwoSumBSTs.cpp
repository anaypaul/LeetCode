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
    void parse(TreeNode * root, unordered_set<int>& s){
        if(root){
            s.insert(root->val);
            parse(root->left, s);
            parse(root->right, s);
        }
    }
    bool find(TreeNode * root, int target, unordered_set<int>& s){
        if(root== NULL){
            return false;
        }
        if(s.find(target - root->val) != s.end()){
            return true;
        }
        if(find(root->left, target, s)){
            return true;
        }
        if(find(root->right, target, s)){
            return true;
        }
        return false;
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1 == NULL || root2==NULL){
            return false;
        }
        unordered_set<int> s;
        parse(root1, s);
        
        return find(root2, target, s);
    }
};