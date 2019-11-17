class TrieNode{
    public:
    bool isEnd;
    char val;
    unordered_map<char,TrieNode *> children;
    TrieNode(char val): isEnd{false}, val{val} {
        
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode * root;
    WordDictionary() {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = new TrieNode('$');
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode * curr = root;
        for(int i = 0; i<word.size(); i++){
            if(curr->children.find(word[i]) == curr->children.end()){
                curr->children[word[i]] = new TrieNode(word[i]);
            }
            curr = curr->children[word[i]];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        // cout<<"searching "<<word<<endl;
        TrieNode * curr = root;
        for(int i = 0; i<word.size(); i++){
            if(word[i] == '.'){
                //explore all the children looking for the string 
                for(auto x: curr->children){
                    string temp = word;
                    temp[i] = x.first;
                    if(search(temp)){
                        return true;
                    }
                }
            }
            if(curr->children.find(word[i]) == curr->children.end()){
                return false;
            }
            curr = curr->children[word[i]];
        }
        return curr->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */