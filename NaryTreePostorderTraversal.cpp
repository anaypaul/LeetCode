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

//Iterative approach 1 using stack and reversing the array
class Solution {
public:
    void dfs(Node * root, vector<int>& res){
        if(root){
            for(auto each : root->children){
                dfs(each, res);
            }
            res.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node *> st;
        if(root){
            st.push(root);
        }
        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            res.push_back(curr->val);
            for(int i = 0; i<curr->children.size(); i++){
                st.push(curr->children[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


//Iterative approach 2 only using stack
class Solution {
public:
    void dfs(Node * root, vector<int>& res){
        if(root){
            for(auto each : root->children){
                dfs(each, res);
            }
            res.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<pair<Node *, int>> st;
        if(root){
            st.push(make_pair(root, 0));
        }
        while(!st.empty()){
            auto curr = st.top();
            if(curr.second < curr.first->children.size()){
                st.top().second = st.top().second + 1;
                st.push(make_pair(curr.first->children[curr.second], 0));
            }else{
                res.push_back(curr.first->val);
                st.pop();
            }
        }
        return res;
    }
};