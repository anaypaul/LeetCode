class Trienode {
    public:
    bool isEnd;
    map<char, Trienode *> children;
    Trienode(){
        isEnd = false;
    }
};

class Trie{
public:
    /** Initialize your data structure here. */
    
    Trie() {
        root = new Trienode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trienode * curr = root;
        for(int i = 0;i<word.length();i++){
            if(curr->children.find(word[i]) == curr->children.end()){
                curr->children.insert(make_pair(word[i], new Trienode()));
            }
            curr = curr->children[word[i]];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trienode * curr = root;
        for(int i = 0;i<word.length();i++){
            if(curr->children.find(word[i]) == curr->children.end()){
                return false;
            }
            curr = curr->children[word[i]];
        }
        if(curr->isEnd ){
            return true;
        }else{
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode *curr = root;
        for(int i = 0;i<prefix.length();i++){
            if(curr->children.find(prefix[i]) == curr->children.end()){
                return false;
            }
            curr = curr->children[prefix[i]];
        }
        return true;
    }
    Trienode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */