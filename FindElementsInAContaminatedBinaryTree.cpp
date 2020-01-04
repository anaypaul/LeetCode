/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        queue<TreeNode *> q;
        q.push(root);
        if(root->val != 0){
            root->val = 0;
            s.insert(0);
        }
        while(!q.empty()){
            auto curr = q.front();
            if(curr->left){
                curr->left->val = curr->val * 2 + 1;
                q.push(curr->left);
                s.insert(curr->left->val);
            }
            if(curr->right){
                curr->right->val = curr->val * 2 + 2;
                q.push(curr->right);
                s.insert(curr->right->val);
            }
            q.pop();
        }
    
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */