class TrieNode{
    public:
    bool isEnd;
    vector<TrieNode *> children;
    TrieNode(){
        isEnd = false;
        vector<TrieNode *> temp(26, nullptr);
        children = temp;
    }
};
class Trie{
    public:
    TrieNode * root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string s){
        TrieNode * curr = root;
        for(int i = s.size()-1; i>=0; i--){
            if(curr->children[s[i]-'a'] == nullptr){
                curr->children[s[i]-'a'] = new TrieNode();
            }
            curr = curr->children[s[i]-'a'];
        }
        curr->isEnd = true;
    }
    bool find(string s){
        TrieNode * curr = root;
        for(int i= s.size()-1; i>=0; i--){
            if(curr->children[s[i]-'a'] == nullptr){
                return false;
            }else{
                curr = curr->children[s[i]-'a'];
                if(curr->isEnd == true){
                    return true;
                }
            }
        }
        return false;
    }
};

class StreamChecker {
public:
    string q;
    Trie * obj;
    int maxLen;
    StreamChecker(vector<string>& words) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        obj = new Trie();
        maxLen = 0;
        for(auto e : words){
            int l = e.size();
            maxLen = max(maxLen, l);
            obj->insert(e);
        }
        q = "";
    }
    bool query(char letter) {
        q = q + letter;
        if(q.size() > maxLen){
            q = q.substr(1);
        }
        return obj->find(q);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */