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
    bool isCousins(TreeNode* root, int x, int y) {
        map<pair<int,int> , int> m; //<<node,depth> and parent> pair
        if(root==NULL){
            return false;
        }
        queue<TreeNode * > q;
        q.push(root);
        int depth = 0;
        m.insert(make_pair(make_pair(root->val, depth) , -1));
        while(!q.empty()){
            int x = q.size();
            for(int i = 0;i<x;i++){
                TreeNode * t = q.front();
                if(t->left){
                    q.push(t->left);
                    m.insert(make_pair( make_pair(t->left->val, depth + 1 ), t->val));
                }
                if(t->right){
                    q.push(t->right);
                    m.insert(make_pair(make_pair(t->right->val, depth + 1), t->val));
                }
                q.pop();
            }
            depth++;
        }
        int n1, d1, p1;
        int n2, d2, p2;
        bool v1 = false;
        bool v2 = false;
        for(auto& xx : m){
            if(xx.first.first == x && !v1){
                n1 = xx.first.first;
                d1 = xx.first.second;
                p1 = xx.second;
                v1 = true;
            }
            if(xx.first.first ==y && !v2){
                n2 = xx.first.first;
                d2 = xx.first.second;
                p2 = xx.second;
                v2 = true;
            }
            if(v1 && v2){
                break;
            }
        }
        return d1==d2 && p1!=p2;
    }
};