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
    int findSecondMinimumValue(TreeNode* root) {
        priority_queue<int, vector<int>, greater<int> > pq;
        queue<TreeNode *> q;
        unordered_set<int> s;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                TreeNode * t = q.front();
                s.insert(t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
        }
        for(auto x : s){
            pq.push(x);
        }
        pq.pop();
        if(pq.empty()){
            return -1;
        }
        return pq.top();
    }
};

//Approach 2
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
    int minVal = -1;
    int secondMinVal = -1;
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr){
            return -1;
        }
        if(root->val < minVal || minVal == -1){
            secondMinVal = minVal;
            minVal = root->val;
        }else if((root->val < secondMinVal && root->val != minVal) || (root->val != minVal && secondMinVal == -1)){
            secondMinVal = root->val;
        }
        findSecondMinimumValue(root->left);
        findSecondMinimumValue(root->right);
        return secondMinVal;
    }
};