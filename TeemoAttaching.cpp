//Approach 1
//Time linear constant space
class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        int n = t.size();
        if(n == 0){
            return 0;
        }
        int res = 0;
        for(int i = 0; i<n-1;i++){
            res += min(t[i+1] - t[i], d);
        }
        return res + d;
    }
};