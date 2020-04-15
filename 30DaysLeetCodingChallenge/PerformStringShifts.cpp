class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int rotate = 0;
        for(auto x : shift){
            if(x[0] == 1){
                rotate += x[1];
            }else{
                rotate -= x[1];
            }
        }
        if(rotate < 0){
            rotate = rotate * -1;
            rotate = rotate % s.size();
            return  s.substr(rotate) + s.substr(0, rotate);
        } else if(rotate > 0){
            rotate = rotate % s.size();
            return s.substr(s.size()- rotate) + s.substr(0, s.size() - rotate);
        }
        return s;
    }
};