class Solution {
public:
    int getMin(int a, int b, int c){
        return min(a , min(b,c));
    }
    int nthUglyNumber(int n) {
        vector<int> res(1,1);
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        while(res.size() < n){
            while(res[p2] * 2 <= res[res.size()-1]){
                p2++;
            }
            while(res[p3] * 3 <= res[res.size()-1]){
                p3++;
            }
            while(res[p5] * 5 <= res[res.size()-1]){
                p5++;
            }
            res.push_back(getMin(res[p2]*2, res[p3]*3, res[p5]*5));
        }
        return res[res.size()-1];
    }
};