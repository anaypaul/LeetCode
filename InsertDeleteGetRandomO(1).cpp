class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> arr;
    unordered_map<int, int> m;
    RandomizedSet() {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()){
            return false;
        }else{
            arr.push_back(val);
            int size = arr.size();
            m[val] = size -1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) != m.end()){
            int index = m[val];
            int last = arr.back();
            m[last] = index;
            arr[index] = last;
            arr.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = rand() % arr.size();
        return arr[n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */