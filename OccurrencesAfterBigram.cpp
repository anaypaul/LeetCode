class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> v;
        stringstream ss(text);
        string temp;
        while(ss >> temp){
            v.push_back(temp);
        }
        vector<string> res;
        unordered_map<string, int> um;
        for(int i = 0; i<v.size()-1; i++){
            if(v[i].compare(first) == 0 && v[i+1].compare(second) == 0){
                if(i+2 < v.size()){
                    res.push_back(v[i+2]);
                }
            }
        }
        return res;  
    }
};