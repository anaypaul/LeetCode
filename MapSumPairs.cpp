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