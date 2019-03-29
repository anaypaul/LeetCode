/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * return its level order traversal as:
 * [
 * [3],
 * [9,20],
 * [15,7]
 * ]
 * /
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//Recursive Approach 
class Solution {
public:
    vector<int> ans_temp;
    void printLevel(TreeNode *root, int level){
        if(root==NULL){
            return ;
        }
        if(level==0){
            ans_temp.push_back(root->val);
        }
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
    int getHeight(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        int left = getHeight(root->left) + 1;
        int right = getHeight(root->right) + 1;
        
        return left > right ? left : right;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int h = getHeight(root);
        for(int i = 0;i<h;i++){
            printLevel(root, i);
            ans.push_back(ans_temp);
            
            ans_temp.clear();
        }
        return ans;
        
    }
};





//Iterative approach.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        TreeNode * curr = root;
        if(!root){
            return res;
        }
        queue<TreeNode * > q;
        vector<int> level;
        vector<TreeNode *> next;
        q.push(root);
        while(!q.empty()){
            while(!q.empty()){
                next.push_back(q.front());
                q.pop();
            }
            for(int i = 0;i<next.size();i++){
                if(next[i]!=NULL){
                    level.push_back(next[i]->val);
                    if(next[i]->left!=NULL){
                        q.push(next[i]->left);
                    } 
                    if(next[i]->right != NULL){
                        q.push(next[i]->right);
                    }
                }
            }
            next.clear();
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};