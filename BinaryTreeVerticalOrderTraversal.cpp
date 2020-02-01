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
    int minX = INT_MAX, maxX=INT_MIN;
    
    void dfs(TreeNode * root, int X, int Y, vector< pair< pair<int, int> , int> >& res){
        if(root){
            res.push_back(make_pair(make_pair(X, Y), root->val));
            minX = min(minX, X);
            maxX = max(maxX, X);
            dfs(root->left, X-1, Y+1, res);
            dfs(root->right, X+1, Y+1, res);
        }
    }
    static bool mycmp(pair<int, int > p1, pair<int , int> p2){
        if(p1.first < p2.first){
            return true;
        }else if(p1.first == p2.first){
            return false;
        }
        return false;
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        vector< pair< pair<int, int> , int> > res;
        dfs(root, 0, 0, res);
        vector<vector<pair<int, int>>> v(maxX - minX + 1, vector<pair<int, int>>());
        for(auto e : res){
            cout<<e.second<<" ("<<e.first.first<<","<<e.first.second<<")"<<endl;
            v[e.first.first - minX].push_back(make_pair(e.first.second, e.second));
        }
        
        for(int i = 0; i<v.size(); i++){
            sort(v[i].begin(), v[i].end(), mycmp);
            vector<int> t;
            for(auto x : v[i]){
                t.push_back(x.second);
            }
            ans.push_back(t);
        }
        return ans;
    }
};