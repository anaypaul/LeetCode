class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator > > m;
    list<int> LRU;
    int cap;
public:
    LRUCache(int capacity) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        cap = capacity;
    }
    void useItem(unordered_map<int, pair<int, list<int>::iterator>>::iterator & itr){
        LRU.erase(itr->second.second);
        LRU.push_front(itr->first);
        itr->second.second = LRU.begin();
    }
    int get(int key) {
        auto itr = m.find(key);
        if(itr == m.end()){
            return -1;
        }
        useItem(itr);
        return itr->second.first;
    }
    
    void put(int key, int value) {
        auto itr = m.find(key);
        if(itr != m.end()){
            useItem(itr);
            m[key] = {value, LRU.begin()};
            return ;
        }
        if(cap == m.size()){
            m.erase(LRU.back());
            LRU.pop_back();
        }
        LRU.push_front(key);
        m.insert({key, {value, LRU.begin()}});
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */