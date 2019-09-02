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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            vector<int> temp;
            for(int i = 0;i<x;i++){
                TreeNode * t = q.front();
                temp.push_back(t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
            res.push_back(temp);
        }
        for(int i = 0;i<res.size();i++){
            if(i%2==1){
                int low = 0;
                int high = res[i].size()-1;
                while(low<=high){
                    int kk = res[i][low];
                    res[i][low] = res[i][high];
                    res[i][high] = kk;
                    low++;
                    high--;
                }
            }
        }
        return res;
    }
};