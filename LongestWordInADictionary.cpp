class TrieNode{
    public:
    bool isEnd;
    char val;
    vector<TrieNode*> children;
    TrieNode(char val): isEnd(false), val(val) {
        vector<TrieNode *> temp(26, nullptr);
        children = temp;
    }
};
class Trie{
    public:
    TrieNode * root;
    string res;
    Trie(){
        root = new TrieNode(' ');
        root->isEnd = true;
    }
    bool insert(string s){
        TrieNode * curr = root;
        int count = 0;
        for(int i = 0; i<s.size(); i++){
            if(curr->isEnd){
                count++;
            }
            if(curr->children[s[i]-'a'] == nullptr){
                curr->children[s[i]-'a'] = new TrieNode(s[i]);
            }
            curr = curr->children[s[i]-'a'];
        }
        curr->isEnd = true;
        if(count == s.size()){
            return true;
        }
        return false;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        if(words.size() == 0){
            return "";
        }
        if(words.size() == 1){
            return words[0];
        }
        sort(words.begin(), words.end());
        Trie * obj = new Trie();
        string res = "";
        for(auto x : words){
            if(obj->insert(x)){
                if(res.size() < x.size()){
                    res = x;
                }else if(res.size() == x.size()){
                    if(res.compare(x) > 0){
                        res = x;
                    }
                }
            }
        }
        return res;
    }
};