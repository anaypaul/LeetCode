class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if(sum % 3 != 0){
            return false;
        }
        int x = sum / 3;
        int s = 0;
        bool part1 = false;
        bool part2 = false;
        for(int i = 0;i<A.size();i++){
            s += A[i];
            if(!part1 && s == sum/3){
                s = 0;
                part1 = true;
            }else if(s == sum/3){
                part2 = true;
            }
            if(part1 && part2){
                break;
            }
        }
        return part1 && part2;
    }
};