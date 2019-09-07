class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int sum1 = accumulate(A.begin(), A.end(), 0);
        int sum2 = accumulate(B.begin(), B.end(), 0);
        int diff = sum2 - sum1;
        int change = diff/2;
        set<int> s;
        for(auto x : B){
            s.insert(x);
        }
        for(auto x : A){
            if(s.find(x + change) !=s.end()){
                res.push_back(x);
                res.push_back(x + change);
                break;
            }
        }
        return res;
    }
};