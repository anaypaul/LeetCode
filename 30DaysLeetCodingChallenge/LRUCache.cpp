class LRUCache {
public:
    unordered_map<int , pair<int, list<int>::iterator>> m;
    list<int> lru;
    int c;
    LRUCache(int capacity) {
        c = capacity;
    }
    
    void process(unordered_map<int, pair<int, list<int>::iterator>>::iterator iter){
        lru.erase(iter->second.second);
        lru.push_front(iter->first);
        iter->second.second = lru.begin();
    }
    int get(int key) {
        auto iter = m.find(key);
        if(iter == m.end()){
            return -1;
        }
        process(iter);
        return iter->second.first;
    }
    
    void put(int key, int value) {
        auto iter = m.find(key);
        if(iter != m.end()){
            process(iter);
            m[key] = {value, lru.begin()};
            return ;
        }
        if(c == m.size()){
            m.erase(lru.back());
            lru.pop_back();
        }
        lru.push_front(key);
        m[key] = {value, lru.begin()};
        return ;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */