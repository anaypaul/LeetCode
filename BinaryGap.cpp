class Solution {
public:
    int binaryGap(int N) {
        vector<int> v;
        while(N>0){
            v.push_back(N&1);
            N = N>>1;
        }
        int res = INT_MIN;
        unordered_map<int,int> um;
        for(int i = 0; i<v.size(); i++){
            if(v[i] == 1 && um.find(v[i]) != um.end()){
                res = max(res, i - um[v[i]] );
            }
            um[v[i]] = i;
        }
        if(res == INT_MIN){
            return 0;
        }
        return res;
    }
};