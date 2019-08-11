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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode *> qt;
        if(root == NULL){
            return res;
        }
        qt.push(root);
        int level = 0;
        while(!qt.empty()){
            level++;
            int n = qt.size();
            long long int sum = 0;
            for(int i = 0;i<n;i++){
                sum = sum + qt.front()->val;
                if(qt.front()->left){
                    qt.push(qt.front()->left);
                }
                if(qt.front()->right){
                    qt.push(qt.front()->right);
                }
                qt.pop();
            }
            res.push_back((double)sum/(double)n);
        }
        return res;
    }
};