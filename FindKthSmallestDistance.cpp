class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> hash(1000000,0);
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                hash[abs(nums[i]-nums[j])]++;
            }
        }
        int x = k;
        for(int i = 0; i<hash.size(); i++){
            if(hash[i] != 0){
                x = x - hash[i];
                if(x <=0){
                    return i;
                }
            }
        }
        return -1;
    }
};