class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size()/4;
        unordered_map<int,int> m;
        for(auto x : arr){
            m[x]++;
        }
        for(auto x : m){
            if(x.second > len){
                return x.first;
            }
        }
        return -1;
    }
};