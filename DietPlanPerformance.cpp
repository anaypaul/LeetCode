class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int ans = 0;
        int curr_cal = 0;
        for(int i = 0;i<calories.size();i++){
            curr_cal += calories[i];
            
            if(i>=k-1){
                if(curr_cal <lower){
                    ans--;
                }else if(curr_cal >upper){
                    ans++;
                }
                curr_cal -= calories[i-k+1];
            }
        }
        return ans;
    }
};