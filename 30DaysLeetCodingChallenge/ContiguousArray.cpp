class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int > m;
        m.insert(make_pair(0, -1));
        int res = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                count++;
            }else{
                count--;
            }
            if(m.find(count) != m.end()){
                res = max(res, i - m[count]);
            }else{
                m[count] = i;
            }
        }
        return res;
    }
};