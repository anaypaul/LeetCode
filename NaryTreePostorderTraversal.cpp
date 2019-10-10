/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
private: 
    vector<int> res;
public:
    void dfs(Node * root){
        if(root){
            for(int i =0; i<root->children.size(); i++){
                if(root->children[i]){
                    dfs(root->children[i]);
                }
            }
            res.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        dfs(root);
        return res;
    }
};