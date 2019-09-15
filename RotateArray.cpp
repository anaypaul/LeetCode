//Time Complexity : O(n)
//Space Complexity : O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.size(),0);
        for(int i = 0;i<nums.size();i++){
            res[(i+k)%nums.size()] = nums[i];
        }
        for(int i = 0;i<nums.size();i++){
            nums[i] = res[i];
        }
    }
};

//Time Complexity : O(n*k)
//Space Complexity : O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp, prev;
        for(int i = 0;i<k;i++){
            prev = nums[nums.size()-1];
            for(int j = 0;j<nums.size();j++){
                temp = nums[j];
                nums[j] = prev;
                prev = temp;
            }
        }
    }
};