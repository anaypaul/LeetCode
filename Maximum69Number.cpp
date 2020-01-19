class Solution {
public:
    int maximum69Number (int num) {
        vector<int> v;
        int x = num;
        while(x>0){
            v.push_back(x%10);
            x = x/10;
        }
        for(int i = v.size()-1; i>=0; i--){
            if(v[i] == 6){
                v[i] = 9;
                break;
            }
        }
        int res = 0;
        for(int i = v.size()-1; i>=0; i--){
            res = res * 10  + v[i];
        }
        return res;
    }
};