class TrieNode{
    public:
    char val;
    bool isEnd;
    vector<TrieNode *> children;
    TrieNode(char val): val{val}, isEnd{false} {
        vector<TrieNode *> temp(26, nullptr);
        children = temp;
    }
    char print(){
        return val;
    }
};
class Trie{
    public:
    TrieNode * root;
    Trie(){
        root = new TrieNode('$');
    }
    void insert(string s){
        TrieNode * curr = root;
        for(int i = 0; i<s.size(); i++){
            if(curr->children[s[i]-'a'] == nullptr){
                curr->children[s[i]-'a'] = new TrieNode(s[i]);
            }
            curr = curr->children[s[i]-'a'];
        }
        curr->isEnd = true;
    }
    TrieNode * findPrefix(string s){
        TrieNode * curr = root;
        TrieNode * prev = nullptr;
        for(int i = 0; i<s.size(); i++){
            if(curr->children[s[i]-'a'] == nullptr){
                return NULL;
            }
            prev = curr;
            curr = curr->children[s[i]-'a'];
        }
        return curr;
    }
    void dfs(TrieNode * curr, string prefix, vector<string>& res){
        if(curr == nullptr || curr->isEnd){
            if(curr == nullptr){
                res.push_back(prefix);
            }else{
                string temp = prefix + curr->print();
                res.push_back(temp);
            }
        }
        if(res.size()==3){
            return;
        }
        prefix += curr->print();
        for(auto x : curr->children){
            if(x!=nullptr){
                dfs(x, prefix, res);
            }
        }
        prefix.pop_back();
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<string>> res;
        Trie * obj = new Trie();
        for(auto x : products){
            obj->insert(x);
        }
        for(int i = 0; i<searchWord.size(); i++){
            string x = searchWord.substr(0, i+1);
            vector<string> temp;
            TrieNode * start = obj->findPrefix(x);
            if(start == nullptr){
                res.push_back(temp);
            }else{
                obj->dfs(start, x.substr(0,x.size()-1), temp);
                res.push_back(temp);
            }
        }
        vector<vector<string>> ans;
        for(auto x : res){
            int k = 3;
            vector<string> temp;
            for(auto y : x){
                k--;
                temp.push_back(y);
                if(k==0){
                    break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};