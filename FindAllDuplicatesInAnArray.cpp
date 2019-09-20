//Time Complexity : O(n)
//Space complexity : O(n) using set to keep track of seen elements. 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> s;
        vector<int> v;
        for(auto x : nums){
            if(s.find(x) == s.end()){
                s.insert(x);
            }else{
                v.push_back(x);
            }
        }
        return v;
    }
};
// Time Complexity : O(n) 
// Space Complexity : O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        for(int i = 0;i<nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0){
                v.push_back(abs(nums[i]));
            }else{
                nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
            }
        }
        return v;
    }
};