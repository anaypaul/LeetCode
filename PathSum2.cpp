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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        vector<string> answer;
        queue<pair<TreeNode*, string>> q;
        q.push(make_pair(root, to_string(root->val)+"," ));
        while(!q.empty()){
            int x = q.size();
            for(int i = 0;i<x;i++){
                pair<TreeNode *, string> p = q.front();
                TreeNode * t = p.first;
                string s = p.second;
                if(sum == t->val && t->left == NULL && t->right==NULL){
                    answer.push_back(s);
                }
                if(t->left){
                    string sleft = s + to_string(t->left->val) +",";
                    t->left->val += t->val;
                    q.push(make_pair(t->left, sleft));
                }
                if(t->right){
                    string sright = s + to_string(t->right->val) + ",";
                    t->right->val += t->val;
                    q.push(make_pair(t->right, sright));
                }
                q.pop();
            }
        }
        
        for(auto s : answer){
            cout<<s<<endl;
            vector<int> v;
            stringstream ss(s);
            for (int i; ss >> i;) {
                v.push_back(i);    
                if (ss.peek() == ',')
                    ss.ignore();
            
            }
            res.push_back(v);
        }
        
        return res;
    }
};