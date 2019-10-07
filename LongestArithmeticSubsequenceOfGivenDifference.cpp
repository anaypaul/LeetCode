class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,int> um;// number , index
        vector<int> dp(arr.size(), 1);
        for(int i = 0; i<arr.size(); i++){
            int target = arr[i] - d;
            // cout<<"searching for number : "<<target<<endl;
            if(um.find(target) == um.end()){
                dp[i] = max(dp[i],1 );
                um[arr[i]] = i;
            }else{
                dp[i] = max(dp[i], dp[um[target]] + 1);
                um[arr[i]] = i;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};