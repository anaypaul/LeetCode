class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> s;
    TwoSum() {
        s.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        s[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        int t;
        for(auto x : s){
            t = value - x.first;
            if(s.find(t)!= s.end()){
                if(t == x.first && s[t]>1){
                    return true;
                }else if(t!=x.first){
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */