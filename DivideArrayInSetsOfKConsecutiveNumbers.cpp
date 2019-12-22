class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k != 0){
            return false;
        }
        sort(nums.begin(), nums.end());
        map<int, int> m;
        for(auto x: nums){
            m[x]++;
        }
        int items = 0;
        while(true){
            bool found = false;
            for(auto itr = m.begin(); itr != m.end(); itr++){
                if(m[itr->first] > 0){
                    found = true;
                    int start = itr->first;
                    for(int i = 0; i<k; i++){
                        if(m[start] > 0){
                            m[start]--;
                            items++;
                        }else{
                            return false;
                        }
                        start++;
                    }
                    break;
                }
            }
            if(found == false){
                break;
            }
        }
        if(items == nums.size()){
            return true;
        }
        return false;
    }
};