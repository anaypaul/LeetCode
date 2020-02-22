class Solution {
public:
    int countBits(int num){
        int c = 0;
        while(num > 0){
            if(num & (num-1)){
                c++;
            }
            num = num & (num-1);
        }
        return c;
    }
    static bool mycmp(pair<int, int > p1, pair<int, int> p2){
        if(p1.second < p2.second){
            return true;
        }else if(p1.second == p2.second){
            if(p1.first < p2.first){
                return true;
            }
        }
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        vector<pair<int, int>> v;
        for(auto each : arr){
            v.push_back({each, countBits(each)});
        }
        sort(v.begin(), v.end(), mycmp);
        for(int i = 0; i<v.size(); i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};