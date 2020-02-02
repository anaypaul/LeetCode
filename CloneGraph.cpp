/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return node;
        }
        
        unordered_map<Node * , Node *> m;
        queue<Node *> q;
        q.push(node);
        m[node] = new Node(node->val);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(auto next : curr->neighbors){
                if(m.find(next) != m.end()){
                    m[curr]->neighbors.push_back(m[next]);
                }else{
                    m[next] = new Node(next->val);
                    m[curr]->neighbors.push_back(m[next]);
                    q.push(next);
                }
            }
        }
        return m[node];
    }
};