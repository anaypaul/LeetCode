class TrieNode{
public:
    char val;
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    int weight;
    TrieNode(char val): val(val), isEnd(false), weight(0){
        
    }
};
class AutocompleteSystem {
public:
    static bool mycmp(pair<string, int> p1, pair<string, int> p2){
        if(p1.second > p2.second){
            return true;
        }else if(p1.second < p2.second){
            return false;
        }else if(p1.second == p2.second){
            if(p1.first.compare(p2.first) <0){
                return true;
            }
        }
        return false;
    }
    TrieNode * root;
    string query;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        root = new TrieNode('$');
        query = "";
        for(int i = 0; i<times.size(); i++){
            insert(sentences[i], times[i]);
        }
    }
    void insert(string s, int weight){
        TrieNode * curr = root;
        for(int i = 0; i<s.size(); i++){
            if(curr->children.find(s[i]) == curr->children.end()){
                curr->children[s[i]] = new TrieNode(s[i]);
            }
            curr = curr->children[s[i]];
        }
        curr->isEnd = true;
        curr->weight += weight;
    }
    vector<string> input(char c) {
        vector<pair<string, int>> res;
        vector<string> result;
        if(c == '#'){
            insert(query, 1);
            query = "";
            return result;
        }
        query = query + c;
        TrieNode * startNode = getPrefix(query);
        if(startNode == nullptr){
            return result;
        }
        dfs(startNode, query, res);
        sort(res.begin(), res.end(), mycmp);
        int count = 0;
        for(auto x : res){
            if(count < 3){
                result.push_back(x.first);
            }
            count++;
        }
        return result;
    }
    TrieNode * getPrefix(string prefix){
        TrieNode * curr = root;
        for(int i = 0; i<prefix.size(); i++){
            if(curr->children.find(prefix[i]) == curr->children.end()){
                return nullptr;
            }
            curr = curr->children[prefix[i]];
        }
        return curr;
    }
    void dfs(TrieNode * curr , string s, vector<pair<string, int>>& res){
        if(curr->isEnd == true){
            res.push_back(make_pair(s, curr->weight));
        }
        for(auto each : curr->children){
            dfs(each.second, s + each.first, res);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */