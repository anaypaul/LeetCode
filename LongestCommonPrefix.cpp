class TrieNode{
    public:
    char val;
    vector<TrieNode *> children;
    bool isEnd;
    int childs;
    TrieNode(char val): val(val), isEnd(false) , childs(0) {
        vector<TrieNode *> temp(26, nullptr);
        children = temp;
    }
};
class Trie{
    public:
    TrieNode * root;
    Trie() {
        root = new TrieNode('$');
    }
    void insert(string s){
        TrieNode * curr = root;
        for(int i = 0; i<s.size(); i++){
            if(curr->children[s[i]-'a'] == nullptr){
                curr->children[s[i]-'a'] = new TrieNode(s[i]);
                curr->childs++;   
            }
            curr = curr->children[s[i]-'a'];
        }
        curr->childs++;
        curr->isEnd = true;
    }
    int search(){
        int len = 0;
        TrieNode * curr = root;
        while(curr != nullptr && curr->childs == 1){
            len++;
            for(int i = 0; i< 26; i++){
                if(curr->children[i] != nullptr){
                    curr = curr->children[i];
                    break;
                }    
            }
            if(curr->childs!= 1){
                break;
            }
        }
        return len;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(strs.size()==0){
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }
        Trie * obj = new Trie();
        for(int i = 0; i<strs.size(); i++){
            obj->insert(strs[i]);
        }
        return strs[0].substr(0, obj->search());
    }
};