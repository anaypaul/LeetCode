class Solution {
public:
    static bool mycmp(pair<int,int> p1 , pair<int, int> p2){
        if(p1.second > p2.second){
            return true;
        }
        return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(auto x : nums){
            um[x] += 1;
        }
        vector<pair<int,int>> v;
        for(auto x : um){
            v.push_back(make_pair(x.first, x.second));
        }
        
        sort(v.begin(), v.end(), mycmp);
        for(auto x : v){
            cout<<x.first<<" "<<x.second<<endl;
        }
        vector<int> res;
        for(int i = 0 ; i< k ; i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};