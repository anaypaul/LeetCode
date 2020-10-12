class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(int i = 0; i<nums.size(); i++){
            int val = 0;
            for(auto x : m){
                if(nums[i] > x.first) {
                    val += x.second;
                }
            }
            res.push_back(val);
        }
        return res;
    }
};

//Approach 2 : Time : O(n) Space : O(1) since size of vector t doesn't increase. 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        vector<int> t(101, 0);
        for(int i = 0; i<nums.size(); i++){
            t[nums[i]]++;
        }
        for(int i = 1; i<t.size(); i++){
            t[i] += t[i-1];
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0){
                res.push_back(0);
            }else{
                res.push_back(t[nums[i]-1]);                
            }
        }
        return res;
        
    }
};