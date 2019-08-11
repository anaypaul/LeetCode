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
    void getLeaf(TreeNode * root, vector<int>& arr){
        if(root==NULL){
            return ;
        }else if(root->left == NULL && root->right == NULL){
            arr.push_back(root->val);
        }
        getLeaf(root->left, arr);
        getLeaf(root->right, arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        getLeaf(root1, tree1);
        getLeaf(root2, tree2);
        bool ans = true;
        if(tree1.size()== tree2.size()){
            for(int i = 0;i<tree1.size();i++){
                if(tree1[i] != tree2[i]){
                    ans = false;
                    break;
                }
            }
        }else{
            ans = false;
        }
        return ans;
    }
};