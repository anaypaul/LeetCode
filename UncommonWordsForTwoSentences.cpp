class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        stringstream s1(A);
        stringstream s2(B);
        vector<string> v1;
        string item;
        while(getline(s1,item, ' ' )){
            v1.push_back(item);
        }
        vector<string> v2;
        while(getline(s2, item, ' ')){
            v2.push_back(item);
        }
        unordered_map<string, int> um;
        for(auto x: v1){
            um[x]++;
        }
        for(auto y: v2){
            um[y]++;
        }
        vector<string> res;
        for(auto each : um){
            if(each.second == 1){
                res.push_back(each.first);
            }
        }
        return res;
    }
};