class TrieNode{
    public:
    char val;
    unordered_map<char, TrieNode * > children;
    bool isEnd; 
    TrieNode(char val): val{val}, isEnd{false} {
        
    }
};
class Trie{
    public:
    TrieNode * root;
    Trie(){
        root = new TrieNode('$');
    }
    bool isCapital(char c){
        return c>='A' && c <='Z';
    }
    void insert(string s){
        TrieNode * curr = root;
        for(int i = 0; i<s.size(); i++){
            if(curr->children.find(s[i]) == curr->children.end()){
                curr->children[s[i]] = new TrieNode(s[i]);
            }
            curr = curr->children[s[i]];
        }
        curr->isEnd = true;
    }
    bool match(string s, string pattern){
        TrieNode * curr = root;
        int idx = 0;
        for(int i = 0; i<s.size(); i++){
            if(idx<pattern.size() && s[i] == pattern[idx]){
                idx++;
            }else{
                if(isCapital(s[i])){
                    return false;
                }
            }
            curr = curr->children[s[i]];
        }
        if(idx == pattern.size()){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<bool> res;
        Trie * obj = new Trie();
        for(int i = 0; i<queries.size(); i++){
            obj->insert(queries[i]);
        }
        for(auto x : queries){
            res.push_back(obj->match(x, pattern));
        }
        return res;
    }
};