class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3){
            return false;
        }
        bool ans = true;
        int i = 0;
        bool increase = false;
        while(i < A.size()-1 && A[i] < A[i+1]){
            i++;
            increase = true;
        }
        if(i == A.size()-1){
            return false;
        }
        bool decrease = false;
        while(i<A.size()-1 && A[i] > A[i+1]){
            i++;
            decrease = true;
        }
        return i == A.size()-1 && increase && decrease;
    }
};