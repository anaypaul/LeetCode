class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int candidate1 = 0;
        int candidate2 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int x : nums){
            if(count1 == 0 && x != candidate2){
                candidate1 = x;
            }
            if(count2 == 0 && candidate1 != x){
                    candidate2 = x;
            }
            if(candidate1 == x){
                count1++;
            }
            if(candidate2 == x){
                count2++;
            }
            if(x!=candidate1 && x != candidate2){
                count1--;
                count2--;
            }
        }
        int check1 = 0;
        int check2 = 0;
        for(auto x : nums){
            if(x == candidate1){
                check1++;
            }
            else if(x == candidate2){
                check2++;
            }
        }
        if(check1 > nums.size()/3 && check2 > nums.size()/3){
            return {candidate1, candidate2};
        }
        if(check1 > nums.size()/3){
            return {candidate1};
        }
        if(check2 > nums.size()/3){
            return {candidate2};
        }
        return {};
    }
};