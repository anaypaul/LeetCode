class Solution {
public:
    static bool mycmp(pair<int, int> p1, pair<int, int> p2){
        return p1.first > p2.first;
    }
    int minSetSize(vector<int>& arr) {
        if(arr.size() == 1){
            return 1;
        }
        vector<pair<int, int>> count;
        unordered_map<int, int> m;
        for(auto x : arr){
            m[x]++;
        }
        for(auto x : m){
            count.push_back({x.second, x.first});
        }
        int n = arr.size();
        sort(count.begin(), count.end(), mycmp);
        int r = 0;
        int res= 0;
        for(int i = 0; i<count.size(); i++){
            if(r < n/2){
                res++;
                r += count[i].first;
            }else{
                break;
            }
        }
        return res;
    }
};