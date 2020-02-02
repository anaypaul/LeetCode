/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MOD 1000000007

class Solution {
public:
    void getSum(TreeNode * root, int & res){
        if(root){
            res += root->val;
            getSum(root->left, res);
            getSum(root->right, res);
        }
    }
    unordered_set<long long int> m;
    long long int all;
    long long int getSum(TreeNode * root){
        if(root == nullptr){
            return 0;
        }
        long long int t = root->val + getSum(root->left) + getSum(root->right);
        m.insert(t);
        return t;
    }
    int maxProduct(TreeNode* root) {
        all = getSum(root);
        long long int res = 0;
        for(auto x : m){
            res = max(res , x * (all - x));
        }
        return res%MOD;
    }
};