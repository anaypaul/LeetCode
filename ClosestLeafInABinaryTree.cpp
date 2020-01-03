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
    void buildGraph(TreeNode * root, unordered_map<TreeNode *, vector<TreeNode *>>& graph){
        if(root != nullptr){
            if(root->left){
                graph[root].push_back(root->left);
                graph[root->left].push_back(root);
                buildGraph(root->left, graph);
            }
            if(root->right){
                graph[root].push_back(root->right);
                graph[root->right].push_back(root);
                buildGraph(root->right, graph);   
            }
            
        }
    }
    TreeNode * find(TreeNode * root, int target){
        if(root!= nullptr){
            if(root->val == target){
                return root;
            }
            TreeNode * left = find(root->left, target);
            if(left != nullptr){
                return left;
            }
            TreeNode * right = find(root->right, target);
            if(right != nullptr){
                return right;
            }
        }
        return nullptr;
    }
    bool isLeaf(TreeNode * root){
        return !root->left && !root->right;
    }
    int findClosestLeaf(TreeNode* root, int k) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //construct a graph
        
        unordered_map<TreeNode *, vector<TreeNode *>> graph;
        buildGraph(root, graph);
        TreeNode * start = find(root, k);
        
        //applying bfs from starting node to find the first leaf node 
        queue<TreeNode *> q;
        unordered_set<TreeNode *> vis;
        q.push(start);
        vis.insert(start);
        while(!q.empty()){
            auto curr = q.front();
            if(isLeaf(curr)){
                return curr->val;
            }
            q.pop();
            for(auto next : graph[curr]){
                if(vis.find(next) == vis.end()){
                    q.push(next);
                    vis.insert(next);
                }
            }
        }
        return 0;
    }
};