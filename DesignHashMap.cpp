//Approach 1
class MyHashMap {
public:
    /** Initialize your data structure here. */
    int * arr;
    MyHashMap() {
        arr = new int[1000001];
        for(int i= 0; i<1000001; i++){
            arr[i] = -1;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        arr[key%1000001] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return arr[key%1000001];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        arr[key % 1000001] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

//Approach 2
class MyHashMap {
public:
    /** Initialize your data structure here. */
    static const int size = 100;
    list<pair<int, int>> hashTable[size];
    MyHashMap() {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    /* hash function to get the bucket number*/
    int hashFunction(int key){
        return key % size;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        bool keyPresent = false;
        
        int idx = hashFunction(key);
        auto& bucket = hashTable[idx];
        auto itr = bucket.begin();
        for(; itr != bucket.end(); itr++){
            if(itr->first == key){
                keyPresent = true;
                itr->second = value;
                break;
            }
        }
        if(!keyPresent){
            bucket.push_back(make_pair(key, value));
            return ;
        }
        return ;
    }
    
    bool isEmpty(){
        int sum{};
        for(int i{}; i<size; i++){
            sum += hashTable[i].size();
        }
        if(!sum){
            return true;
        }
        return false;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if(isEmpty()){
            return -1;
        }
        int value{};
        bool keyPresent = false;
        int idx = hashFunction(key);
        auto& bucket = hashTable[idx];
        auto itr = bucket.begin();
        for(; itr != bucket.end(); itr++){
            if(itr->first == key){
                keyPresent = true;
                value = itr->second;
                break;
            }
        }
        if(!keyPresent){
            return -1;
        }
        return value;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(isEmpty()){
            return ;
        }
        bool keyPresent = false;
        int index = hashFunction(key);
        auto& bucket = hashTable[index];
        auto itr = bucket.begin();
        for(; itr != bucket.end(); itr++){
            if(itr->first == key){
                keyPresent = true;
                bucket.erase(itr);
                break;
            }
        }
        if(!keyPresent){
            return ;
        }
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */