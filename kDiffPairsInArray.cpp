class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        unordered_map<int,int> m;
        for(int n : nums){
            m[n]++;
        }
        int res= 0;
        
        for(auto& p : m ){
            res += k * m.count(p.first + k) || !k && p.second>1;
        }
        return res;
    }
};