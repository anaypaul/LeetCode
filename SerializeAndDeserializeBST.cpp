/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "[]";
        }
        string res = "[";
        bool first = true;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(first == true){
                first = false;
            }else{
                res += ",";
            }
            if(curr == nullptr){
                res += "null";
            }else{
                res += to_string(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() <= 2){
            return nullptr;
        }
        data = data.substr(1, data.size()-2);
        cout<<data<<endl;
        TreeNode * root = new TreeNode(-1);
        queue<TreeNode **> q;
        q.push(&root);
        int num , sign;
        for(int i = 0; i<data.size(); i++){
            auto curr = q.front();
            q.pop();
            if(data[i] == 'n'){
                delete *curr;
                *curr = nullptr;
                while(i<data.size() && data[i]!= ','){
                    i++;
                }
            }else{
                num = 0;
                sign = 1;
                if(data[i]== '-'){
                    sign = -1;
                    i++;
                }
                while(i<data.size() && data[i] != ','){
                    num = num * 10 + data[i] -'0';
                    i++;
                }
                num = num * sign;
                (*curr)->val = num;
                (*curr)->left = new TreeNode(-1);
                (*curr)->right = new TreeNode(-1);
                q.push(&((*curr)->left));
                q.push(&((*curr)->right));
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));