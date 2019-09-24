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
    unordered_map<int, unordered_set<int>> graph;
    unordered_map<int, vector<int>> distance;
    void buildGraph(TreeNode *root){
        if(root==NULL){
            return ;
        }
        int value = root->val;
        if(root->left){
            int leftValue = root->left->val;
            graph[value].insert(leftValue);
            graph[leftValue].insert(value);
            buildGraph(root->left);
        }
        if(root->right){
            int rightValue = root->right->val;
            graph[value].insert(rightValue);
            graph[rightValue].insert(value);
            buildGraph(root->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        buildGraph(root);
        int dist = 0;
        queue<pair<int, int> > q;
        set<int> visited;
        q.push(make_pair(target->val, 0));
        visited.insert(target->val);
        while(!q.empty()){
            int x = q.size();
            for(int i =0 ; i<x;i++){
                auto node = q.front();
                int curr = node.first;
                int level = node.second;
                if(level == K){
                    while(!q.empty()){
                        pair<int,int>  val = q.front();
                        cout<<val.first<<" ";
                        res.push_back(val.first);
                        q.pop();
                    }
                    return res;
                }
                for(int temp : graph[curr]){
                    if(visited.find(temp) == visited.end()){
                        q.push(make_pair(temp, level+1));
                        visited.insert(temp);
                    }
                }
                q.pop();
            }
        }
        return res;
    }
};