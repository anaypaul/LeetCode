/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<int,int> um;
class Solution {
public:
    int solve(TreeNode * root){
        if(root){
            int sum = root->val;
            int left_subtree_sum = solve(root->left);
            int right_subtree_sum = solve(root->right);
            um[sum + left_subtree_sum + right_subtree_sum]++;
            return sum + left_subtree_sum + right_subtree_sum;
        }
        return 0;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        int maxi = INT_MIN;
        for(auto x : um){
            cout<<x.first<<" "<<x.second<<endl;
            if(maxi < x.second){
                maxi = x.second;
            }
        }
        vector<int> res;
        for(auto x : um){
            if(maxi == x.second){
                res.push_back(x.first);
            }
        }
        um.clear();
        return res;
    }
};