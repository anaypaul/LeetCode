class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m.insert(make_pair(nums[i], i));
            }else{
                if(abs(i - m[nums[i]]) <= k){
                    return true;
                }else{
                    m[nums[i]] = i;
                }
            }
        }
        return false;
    }
};