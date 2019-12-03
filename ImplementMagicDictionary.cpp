class TrieNode{
    public:
    char val;
    bool isEnd;
    vector<TrieNode *> children;
    TrieNode(char ch){
        val = ch;
        isEnd = false;
        vector<TrieNode *> temp(26, nullptr);
        children = temp;
    }
};
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode * root;
    unordered_map<int, vector<string>> m;
    MagicDictionary() {
        root = new TrieNode('$');
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto each : dict){
            insert(each);
            m[each.size()].push_back(each);
        }
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
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if(m.find(word.size()) == m.end()){
            return false;
        }
        for(auto each : m[word.size()]){
            int mismatch = 0;
            for(int i = 0; i<word.size(); i++){
                if(word[i] != each[i]){
                    if(mismatch>1){
                        break;
                    }
                    mismatch++;
                }
            }
            if(mismatch == 1){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */