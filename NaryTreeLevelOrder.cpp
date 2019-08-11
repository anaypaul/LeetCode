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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        queue<Node*> qt;
        qt.push(root);
        int level = 0;
        while(!qt.empty()){
            level++;
            queue<Node *> temp;
            vector<int> arr;
            while(!qt.empty()){
                arr.push_back(qt.front()->val);
                for(Node * x : qt.front()->children){
                    temp.push(x);
                }
                qt.pop();
            }
            qt = temp;
            res.push_back(arr);
            arr.clear();
        }
        cout<<"levels : "<<level<<endl;
        return res;
    }
};