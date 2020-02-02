class Solution {
public:
    static bool mycmp(pair<int, int> p1, pair<int, int> p2){
        if(p1.first < p2.first){
            return true;
        }else if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        return false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int, int>> count;
        int idx = 0;
        for(auto x : mat){
            int c =0 ;
            for(auto y : x ){
                if(y){
                    c++;
                }
            }
            count.push_back({c, idx});
            idx++;
        }
        sort(count.begin(), count.end(), mycmp);
        vector<int> res;
        for(int i = 0; i<k; i++){
            res.push_back(count[i].second);
        }
        
        return res;
    }
};