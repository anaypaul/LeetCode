//Approach 1
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> us;
        int rep = -1;
        for(auto x: nums){
            if(us.find(x)== us.end()){
                us.insert(x);
            }else{
                rep = x;
            }
        }
        int lost = -1;
        for(int i = 1; i<=nums.size(); i++){
            if(us.find(i) == us.end()){
                lost = i;
                break;
            }
        }
        return {rep, lost};
    }
};

//Approach 2
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int rep = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[abs(nums[i]) - 1] < 0){
                rep = abs(nums[i]);
            }else{
                nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
            }
        }
        int lost = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > 0){
                lost = i+1;
            }
        }
        return {rep, lost};
    }
};