/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int min_X = INT_MAX;
int max_X = INT_MIN;
vector<pair< pair<int,int>, int >> arr;
class Solution {
public:
    
    static void helper(TreeNode * root, int X, int Y){
        if(root){
            arr.push_back(make_pair(make_pair(X,Y), root->val));
            if(min_X > X){
                min_X = X;
            }
            if(max_X < X){
                max_X = X;
            }
        }else{
            return ;
        }
        helper(root->left, X-1,Y-1);
        helper(root->right, X+1,Y-1);
    }
    static bool myCompare(pair< pair<int,int>, int > p1, pair< pair<int,int>, int > p2){
        if(p1.first.first != p2.first.first){
            return p1.first.first < p2.first.first;
        }else if(p1.first.second != p2.first.second){
            return p1.first.second > p2.first.second;
        }else{
            return p1.second < p2.second;
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root,0,0);   
        std::vector<std::vector<int>> v(max_X - min_X +1, std::vector<int>(0));
        sort(arr.begin(), arr.end(),myCompare );
        for(int i = 0;i<arr.size();i++){
            v[arr[i].first.first + abs(min_X)].push_back(arr[i].second);
        }
        arr.clear();
        min_X = INT_MAX;
        max_X = INT_MIN;
        return v;
    }
};