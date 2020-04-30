class FirstUnique {
public:
    map<int,int> m;
    vector<int> v;
    FirstUnique(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(m.find(nums[i])==m.end()){
                v.push_back(nums[i]);
                m.insert({nums[i],i});
            }else{
                m[nums[i]] = i;
            }
        }
    }
    
    int showFirstUnique() {
        for(int i=0; i<v.size(); i++) {
            if(m[v[i]] == i){
                return v[i];
            }
        }
        return -1;
    }
    
    void add(int value) {
        if(m.find(value)!=m.end()){
            m[value] = v.size();
        }else{
            m.insert({value,v.size()});
            v.push_back(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */