class Solution {
public:
    static bool mycmp(pair<int,int>& p1, pair<int,int>& p2){
        return p1.second > p2.second;
    }
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i = 0; i<nums.size(); i++){
            v.push_back(make_pair(i, nums[i]));
        }
        sort(v.begin(), v.end(), mycmp);
        vector<string> res(nums.size());
        int rank = 4;
        for(int i = 0; i<v.size(); i++){
            if(i == 0){
                res[v[i].first] = "Gold Medal";
            }else if(i == 1){
                res[v[i].first] = "Silver Medal";
            }else if(i==2){
                res[v[i].first] = "Bronze Medal";
            }else{
                res[v[i].first] = to_string(rank);
                rank++;
            }
        }
        return res;
    }
};