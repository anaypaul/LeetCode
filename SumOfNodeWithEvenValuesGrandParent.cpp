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
    void dfs(TreeNode * root, TreeNode * parent, unordered_map<TreeNode *, TreeNode *>& m){
        if(root == nullptr){
            return;
        }
        m[root] = parent;
        dfs(root->left, root, m);
        dfs(root->right, root, m);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        TreeNode * parent = new TreeNode(-1);
        unordered_map<TreeNode * , TreeNode * > m; //store parent of each node. node->parent pairs
        dfs(root, nullptr, m );
        for(auto x : m){
            TreeNode * node = x.first;
            if(x.second == nullptr){
                continue;
            }
            TreeNode * gparent = m[x.second];
            if(gparent !=  nullptr && gparent->val % 2 == 0){
                res += node->val;
            }
        }
        return res;
    }
};

//Approach 2 : Without using map
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
    void dfs(TreeNode * root, TreeNode * parent, TreeNode * grandParent, int& res){
        if(root == nullptr){
            return ;
        }
        if(grandParent != nullptr && grandParent->val % 2 == 0){
            res += root->val;
        }
        dfs(root->left, root, parent, res);
        dfs(root->right, root, parent, res);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        dfs(root, nullptr, nullptr, res);
        return res;
    }
};