class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int count = 0;
        for(auto x : arr){
            if(x == 0){
                count++;
            }
        }
        if(count >=2){
            return true;
        }
        for(auto each : s){
            if(each != 0 &&s.find(each * 2) != s.end()){
                return true;
            }
        }
        return false;
    }
};