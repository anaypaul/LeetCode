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
public:
    int maxDepth1(Node* root) {
        int level = 0;
        if(root == NULL){
            return level;
        }
        queue<Node*> qt;
        qt.push(root);
        while(!qt.empty()){
            level++;
            int size = qt.size();
            for(int i = 0;i<size;i++){
                for(Node * x : qt.front()->children){
                    qt.push(x);
                }
                qt.pop();
            }
        }
        return level;
    }
    int maxDepth(Node* root) {
        if(root== NULL){
            return 0;
        }
        int max_h = 1;
        for(Node * x : root->children){
            int h = 1 + maxDepth(x);
            max_h = max(max_h, h);
        }
        return max_h;
    }
};