class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count[60] = {0};
        for(int i = 0;i<time.size();i++){
            time[i] = time[i]%60;
            ++count[time[i]];
        }
        int pairs = 0;
        pairs += count[60/2] * (count[60/2] -1)/2;
        pairs += count[0] * (count[0] - 1)/2;
        for(int i = 1;i<60/2;i++){
            pairs += count[i] * count[60-i];
        }
        return pairs;
    }
};