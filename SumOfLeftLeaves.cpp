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
    bool checkLeaf(TreeNode * node){
        return !node->left && !node->right; 
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            for(int i = 0;i<x;i++){
                TreeNode * t = q.front();
                if(t->left){
                    if(checkLeaf(t->left)){
                        cout<<t->left->val<<endl;
                        sum+= t->left->val;
                    }
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
        }
        return sum;
    }
};

//Approach 2 : recursive solution
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
        return root->left == nullptr && root->right==nullptr;
    }
    void dfs(TreeNode * root, int& sum, bool flag){
        if(root){
            if(isLeaf(root) && flag){
                sum += root->val;
            }
            dfs(root->left, sum, true);
            dfs(root->right, sum, false);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, false);
        return sum;
    }
};