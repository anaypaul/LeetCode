class Solution {
public:
    
    int minTaps(int n, vector<int>& ranges) {
        vector<int> cover(n + 1);
        for(int i = 0; i<ranges.size(); i++){
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            cover[start] = max(cover[start], end - start);
        }
        int maxReachPos = cover[0];
        int currMaxReachPos = cover[0];
        int step = 1;
        for(int i = 1; i<= min(n, maxReachPos); i++){
            currMaxReachPos = max(currMaxReachPos, i + cover[i]);
            if(i == n){
                return step;
            }
            if(i == maxReachPos){
                step++;
                maxReachPos = currMaxReachPos;
            }
        }
        return -1;
    }
};