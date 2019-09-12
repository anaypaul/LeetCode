class Solution {
public:
    
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> arr;
        int num = 0;
        for(int i = 0;i<A.size();i++){
            num = num*2 + A[i];
            num %= 5;
            arr.push_back(num%5==0);
        }
        return arr;
    }
};