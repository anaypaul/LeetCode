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
    unordered_map<string, TreeNode*> string2tree;
    unordered_map<TreeNode *, string> tree2string;
    int count = 0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        cout.tie(0);cin.tie(0);
        string s = to_string(count++);
        string2tree[s] = root;
        tree2string[root] = s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::ios_base::sync_with_stdio(false);
        cout.tie(0);cin.tie(0);
        return string2tree[data];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));