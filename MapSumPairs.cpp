//Approach 1 : without using trie
class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> prefixsum;
    unordered_map<string, int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int difference = val - m[key];
        m[key] = val;
        string s = "";
        for(auto x : key){
            s += x;
            prefixsum[s] += difference;
        }
    }
    
    int sum(string prefix) {
        return prefixsum[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

//Approach 2: Using Trie DS
class TrieNode{
    public:
    char val;
    int weight;
    unordered_map<char, TrieNode*> children;
    TrieNode(char val): val{val}, weight{0} {
        
    }
};
class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> m;
    TrieNode * root;
    MapSum() {
        root = new TrieNode('$');
        m.clear();
    }
    
    void insert(string key, int val) {
        int difference;
        if(m.find(key) != m.end()){
            difference = val - m[key];
        }else{
            difference = val;
        }
        m[key] = val;
        TrieNode * curr = root;
        for(int i = 0; i<key.size(); i++){
            if(curr->children.find(key[i]) == curr->children.end()){
                curr->children[key[i]] = new TrieNode(key[i]);
                curr->children[key[i]]->weight = difference; 
            }else{
                curr->children[key[i]]->weight += difference;
            }
            curr = curr->children[key[i]];
        }
    }
    
    int sum(string prefix) {
        int res = 0;
        TrieNode * curr = root;
        for(int i = 0; i<prefix.size(); i++){
            if(curr->children.find(prefix[i]) != curr->children.end()){
                res = curr->children[prefix[i]]->weight;
            }else{
                return 0;
            }
            curr = curr->children[prefix[i]];
            if(curr == nullptr){
                break;
            }
            res = curr->weight;
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */