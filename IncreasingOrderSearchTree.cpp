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
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> arr;
        if(root == NULL){
            return NULL;
        }else{
            TreeNode * curr = root;
            while(curr!=NULL){
                if(curr->left ==NULL){
                    arr.push_back(curr->val);
                    curr = curr->right;
                }else{
                    TreeNode * pre = curr->left;
                    while(pre->right != curr && pre->right != NULL){
                        pre = pre->right;
                    }
                    
                    if(pre->right == NULL){
                        pre->right = curr;
                        curr = curr->left;
                    }else{
                        pre->right = NULL;
                        arr.push_back(curr->val);
                        curr = curr->right;
                    }
                }
            }
        }
        TreeNode * r1 = new TreeNode(arr[0]);
        TreeNode * curr = r1;
        for(int i = 1;i<arr.size();i++){
            curr->left = NULL;
            curr->right = new TreeNode(arr[i]);
            curr = curr->right;
        }
        return r1;
    }
};

//Recursive solution
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
    vector<int> res;
    void inorder(TreeNode * root){
        if(root){
            inorder(root->left);
            res.push_back(root->val);
            inorder(root->right);
        }else{
            return;
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode * root_new = new TreeNode(-1);
        TreeNode * curr = root_new;
        for(int i = 0;i<res.size(); i++){
            curr->right = new TreeNode(res[i]);
            curr = curr->right;
        }
        return root_new->right;
    }
};