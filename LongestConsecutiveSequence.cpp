//Approach 1 : Time O(nlogn) since sorting the array 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> s(nums.begin(), nums.end());
        nums.clear();
        for(auto x : s){
            nums.push_back(x);
        }
        sort(nums.begin(), nums.end());
        int res = 1;
        int ans = 1;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] + 1 == nums[i+1]){
                res++;
            }else{
                res= 1;
            }
            ans = max(res, ans);
        }
        return ans;
    }
};
//Approach 2
//Time : O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(auto x : s){
            if(s.find(x-1) == s.end()){
                int curr =1;
                int num = x;
                while(s.find(num + 1) != s.end()){
                    num = num + 1;
                    curr++;
                }
                ans = max(curr, ans);
            }
        }
        return ans;
    }
};