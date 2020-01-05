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
    void dfs(TreeNode * root, int prev , int curr, int & res){
        res = max(res, curr);
        if(root!= nullptr){
            if(prev + 1 == root->val){
                dfs(root->left, root->val, curr + 1, res);
                dfs(root->right, root->val, curr + 1, res);
            }else{
                dfs(root->left, root->val, 1, res);
                dfs(root->right, root->val, 1, res);
            }
        }
    }
    int longestConsecutive(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(root == nullptr || (!root->left && !root->right)){
            return root==nullptr ? 0 : 1;
        }
        int res = INT_MIN;
        int prev = INT_MIN;
        dfs(root, prev, 1, res);
        return res;
    }
};

//Approach 2 : using iterative BFS
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
    void dfs(TreeNode * root, int prev , int curr, int & res){
        res = max(res, curr);
        if(root!= nullptr){
            if(prev + 1 == root->val){
                dfs(root->left, root->val, curr + 1, res);
                dfs(root->right, root->val, curr + 1, res);
            }else{
                dfs(root->left, root->val, 1, res);
                dfs(root->right, root->val, 1, res);
            }
        }
    }
    int longestConsecutive(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(root == nullptr){
            return 0;
        }
        int res = 1;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 1));
        while(!q.empty()){
            auto curr = q.front();
            if(curr.first->left){
                q.push(make_pair(curr.first->left, curr.first->left->val == curr.first->val +1 ? curr.second + 1 : 1));
            }
            if(curr.first->right){
                q.push(make_pair(curr.first->right, curr.first->right->val == curr.first->val +1 ? curr.second + 1 : 1));
            }
            q.pop();
            res = max(res, curr.second);
        }
        return res;
    }
};