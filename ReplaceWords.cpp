class TrieNode{
    public:
    char val;
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(char val){
        val = val;
        isEnd = false;
        vector<TrieNode *> temp(26, nullptr);
        children = temp;
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
    
    bool isPrefix(string s){
        TrieNode * curr = root;
        for(int i = 0; i<s.size(); i++){
            if(curr->children[s[i]-'a'] == nullptr){
                return false;
            }
            curr = curr->children[s[i]-'a'];
        }
        return curr != nullptr;
    }
    bool find(string s){
        TrieNode * curr = root;
        for(int i = 0; i<s.size(); i++){
            if(curr->children[s[i]-'a'] == nullptr){
                return false;
            }
            curr = curr->children[s[i]-'a'];
        }
        return curr->isEnd;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        stringstream ss(sentence);
        string t;
        vector<string> v;
        while(ss>>t){
            v.push_back(t);
        }
        Trie * obj = new Trie();
        for(auto each : dict){
            obj->insert(each);
        }
        string res = "";
        for(int i = 0; i<v.size(); i++){
            string item = v[i];
            for(int j = 0; j<=v[i].size(); j++){
                if(obj->find(v[i].substr(0, j))){
                    item = v[i].substr(0,j);
                    break;
                }
            }
            res += item + " ";
        }
        return res.substr(0, res.size()-1);
    }
};