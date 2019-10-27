class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.size() == 0 && lower != upper){
            res.push_back(to_string(lower) + "->" + to_string(upper));
            return res;
        }else if(nums.size() == 0 && lower == upper){
            res.push_back(to_string(lower));
            return res;
        }
        long long int minval = *min_element(nums.begin(), nums.end());
        long long int maxval = *max_element(nums.begin(), nums.end());
        if(lower != minval){
            if((long)minval - (long)lower == 1){
                string s = to_string(lower);
                res.push_back(s);
            }else if((long )minval - (long)lower > 1){
                string s = to_string(lower) + "->" + to_string(minval -1);
                res.push_back(s);
            }
        }
        int i = 0;
        for(i = 0; i<nums.size()-1; i++){
            if((long long int)nums[i+1] - (long long int)nums[i] != 1){
                if((long long int)nums[i+1] - (long long int)nums[i] == 2){
                    string s = to_string(nums[i+1] -1 );
                    res.push_back(s);
                }else if((long long int)nums[i+1] - (long long int)nums[i] > 2){
                    string s = to_string(nums[i]+1)+ "->" +to_string(nums[i+1]- 1);
                    res.push_back(s);
                }
            }
        }
        
        if(upper != maxval){
            if(upper - maxval == 1){
                string s = to_string(upper);
                res.push_back(s);
            }else if(upper - maxval > 1){
                string s = to_string(maxval+1) + "->" + to_string(upper);
                res.push_back(s);
            }
        }
        return res;
    }
};