class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> arr;
    vector<bool> present;
    MyHashSet() {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> temp(1000001);
        vector<bool> tempp(1000001, false);
        arr = temp;
        present = tempp;
    }
    
    void add(int key) {
        arr[key%1000001] = key;
        present[key%1000001] = true;
    }
    
    void remove(int key) {
        present[key%1000001] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return present[key%1000001];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */