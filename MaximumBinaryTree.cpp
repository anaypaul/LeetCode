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
    TreeNode * addNode(vector<int> nums, int low, int high){
        if(low<=high){
            int maxVal = INT_MIN;
            int maxIndex = -1;
            for(int i = low; i<=high; i++){
                if(maxVal < nums[i]){
                    maxVal = nums[i];
                    maxIndex = i;
                }
            }
            TreeNode * t = new TreeNode(maxVal);
            t->left = addNode(nums, low, maxIndex-1);
            t->right = addNode(nums, maxIndex+1, high);
            return t;
        }
        return nullptr;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()== 0){
            return nullptr;
        }
        if(nums.size()==1){
            return new TreeNode(nums[0]);
        }
        int maxVal = INT_MIN;
        int maxIndex = -1;
        for(int i = 0; i<nums.size(); i++){
            if(maxVal < nums[i]){
                maxVal = nums[i];
                maxIndex = i;
            }
        }
        TreeNode * root = new TreeNode(maxVal);
        root->left = addNode(nums,  0, maxIndex-1);
        root->right = addNode(nums, maxIndex+1, nums.size()-1);
        return root;
    }
};