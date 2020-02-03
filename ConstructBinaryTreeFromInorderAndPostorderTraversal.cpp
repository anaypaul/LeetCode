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
    TreeNode * helper(vector<int>& inorder, int ileft, int iright, vector<int>& postorder, int pleft, int pright){
        if(ileft > iright){
            return nullptr;
        }
        TreeNode * root = new TreeNode(postorder[pright]);
        int i = 0;
        for(i = ileft; i<=iright; i++){
            if(root->val == inorder[i]){
                break;
            }
        }
        root->left= helper(inorder, ileft, i-1, postorder, pleft, pleft + i - ileft -1);
        root->right = helper(inorder, i+1, iright, postorder, pleft + i - ileft, pright -1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || inorder.size() != postorder.size()){
            return nullptr;
        }
        TreeNode * root = helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        return root;
    }
    
};

//Clean code
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
    unordered_map<int, int> m;
    int idx;
    TreeNode * helper(vector<int>& postorder, int low, int high){
        if(low > high ){
            return nullptr;
        }
        TreeNode * temp = new TreeNode(postorder[idx--]);
        
        temp->right = helper(postorder, m[temp->val] + 1, high);
        temp->left = helper(postorder, low, m[temp->val] - 1);
        return temp;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0){
            return nullptr;
        }
        int n = inorder.size();
        for(int i = 0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        idx = n-1;
        TreeNode * node = new TreeNode(postorder[idx--]);
        node->right = helper(postorder, m[node->val] + 1, n-1);
        node->left = helper(postorder, 0, m[node->val] - 1);
        return node;
    }
    
};