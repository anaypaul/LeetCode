class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        set<pair<int,int>> s;
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                if(abs(nums[i] - nums[j]) == k){
                    int x = min(nums[i], nums[j]);
                    int y = max(nums[i], nums[j]);
                    pair<int,int> p (x,y);
                    if(s.find(p) == s.end()){
                        res++;
                        s.insert(p);
                    }
                }
            }
        }
        return res;
    }
};