//Approach 1 :[TLE] using BFS with TLE
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
    int widthOfBinaryTree(TreeNode* root) {
        vector<vector<TreeNode *>> vals;
        int res = 0;
        if(root == NULL){
            return res;
        }
        res = 1;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            vector<TreeNode *> temp;
            bool allNull = true;
            int startidx = -1;
            int endidx = -1;
            for(int i = 0; i<x; i++){
                auto curr = q.front();
                temp.push_back(curr);
                if(curr == NULL){
                    q.push(NULL);
                    q.push(NULL);
                }else{
                    allNull = false;
                    if(startidx == -1 && endidx == -1){
                        startidx = i;
                    }else{
                        endidx = i;
                    }
                    res = max(res, endidx - startidx + 1);
                    if(curr->left){
                        q.push(curr->left);
                    }else{
                        q.push(NULL);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }else{
                        q.push(NULL);
                    }
                }
                q.pop();
            }
            if(allNull){
                break;
            }
            vals.push_back(temp);
        }
        return res;
    }
};

//Approach 2 :[ACCEPTED] BFS with TreeNode indexing stored as pair in a queue
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *, unsigned long long int >> q;
        int res = 0;
        if(root == NULL){
            return res;
        }
        res = 1;
        q.push(make_pair(root, 1));
        while(!q.empty()){
            int x = q.size();
            int curr_width = q.back().second - q.front().second + 1;
            res = max(res, curr_width);
            for(int i = 0; i<x; i++){
                auto t = q.front();
                if(t.first->left){
                    q.push(make_pair(t.first->left, t.second * 2));
                }
                if(t.first->right){
                    q.push(make_pair(t.first->right, t.second * 2 + 1));
                }
                q.pop();
            }
        }
        return res;
    }
};