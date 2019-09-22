class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int bal = 5000;
        int ret = 0;
        for(auto& x : arr){
            if(bal - x>=0){
                ret++;
                bal -= x;
            }else{
                break;
            }
        }
        return ret;
    }
};