class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 0){
            return {};
        }
        if(n == 1){
            return {0};
        }
        vector<int> res;
        if(n % 2 == 0){
            int val = 1;
            for(int i = 0; i<n/2; i++){
                res.push_back(val);
                res.push_back(-1 * val);
                val++;
            }
        }else{
            res.push_back(0);
            int val = 1;
            for(int i = 0; i<n/2; i++){
                res.push_back(val);
                res.push_back(val * -1);
                val++;
            }
        }
        return res;
    }
};