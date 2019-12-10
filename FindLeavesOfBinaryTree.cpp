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
        if(!root){
            return false;
        }
        return !root->left && !root->right;
    }
    void getLeaf(TreeNode * root, vector<int> & temp){
        if(root){
            getLeaf(root->left, temp);
            getLeaf(root->right, temp);
            if(isLeaf(root)){
                temp.push_back(root->val);
                return;
            }
        }
    }
    void removeleaf(TreeNode * root){
        if(root){
            if(isLeaf(root->left)){
                root->left = NULL;
            }else{
                removeleaf(root->left);
            }
            if(isLeaf(root->right)){
                root->right = NULL;
            }else{
                removeleaf(root->right);
            }
        }
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while(root){
            vector<int> temp;
            if(isLeaf(root)){
                temp.push_back(root->val);
                root = NULL;
            }
            getLeaf(root, temp);
            res.push_back(temp);
            removeleaf(root);
        }
        return res;
    }
};

//Implementation 2
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
        return !root->left && !root->right;
    }
    void perform(TreeNode * root, vector<int>& v){
        if(root!= nullptr){
            if(root->left != nullptr && isLeaf(root->left)){
                v.push_back(root->left->val);
                root->left = nullptr;
            }
            if(root->right != nullptr && isLeaf(root->right)){
                v.push_back(root->right->val);
                root->right = nullptr;
            }
            perform(root->left, v);
            perform(root->right, v);
        }
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        while(root != nullptr && isLeaf(root) == false){
            vector<int> v;
            perform(root, v);
            res.push_back(v);
        }
        res.push_back({root->val});
        return res;
    }
};