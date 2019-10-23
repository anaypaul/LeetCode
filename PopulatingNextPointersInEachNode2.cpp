/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        vector<vector<Node*>> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            vector<Node*> v;
            for(int i = 0; i<x; i++){
                Node * t = q.front();
                v.push_back(t);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                q.pop();
            }
            res.push_back(v);
            v.clear();
        }
        for(int i = 0; i<res.size(); i++){
            for(int j = 0; j<res[i].size(); j++){
                if(j == res[i].size()-1){
                    res[i][j]->next = NULL;
                }else{
                    res[i][j]->next = res[i][j+1];    
                }
            }
        }
        return root;
    }
};