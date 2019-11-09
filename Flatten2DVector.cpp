class Vector2D {
public:
    vector<int> arr;
    vector<int>::iterator itr;
    Vector2D(vector<vector<int>>& v) {
        for(auto x: v){
            for(auto y : x){
                arr.push_back(y);
            }
        }
        itr = arr.begin();
    }
    
    int next() {
        int item = *itr;
        itr++;
        return item;
    }
    
    bool hasNext() {
        return itr != arr.end();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */