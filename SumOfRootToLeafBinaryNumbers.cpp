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
        if(root == NULL){
            return false;
        }
        if(!root->left && !root->right){
            return true;
        }
        return false;
    }
    int getInt(char ch){
        return ch == '1' ? 1 : 0;
    }
    int powerof2(int exp){
        int base = 2;
        if(exp == 0){
            return 1;
        }
        return 1<<exp;
    }
    int binaryToInt(string s){
        int res = 0;
        int power = 0;
        for(int i = s.length()-1; i>=0 ; i--){
            res += getInt(s[i]) * powerof2(power);
            power++;
        }
        return res;
    }
    void dfs(TreeNode * root, string s, vector<string>& v){
        if(isLeaf(root)){
            s = s + to_string(root->val);
            v.push_back(s);
            return;
        }
        if(root->left){
            dfs(root->left, s + to_string(root->val), v);
        }
        if(root->right){
            dfs(root->right, s + to_string(root->val), v);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> v;
        dfs(root, "", v);
        int res = 0;
        for(auto each : v){
            res += binaryToInt(each);
        }
        return res;
    }
};