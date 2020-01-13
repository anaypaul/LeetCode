class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int res = 0;
        int n = A.size();
        unordered_map<int, int> sum1;
        for(int a : A){
            for(int b : B){
                sum1[a+b]++;
            }
        }
        int target = 0;
        for(int c : C){
            for(int d : D){
                if(sum1.find(target - (c+d)) != sum1.end()){
                    res += sum1[target - (c+d)];
                }
            }
        }
        return res;
    }
};