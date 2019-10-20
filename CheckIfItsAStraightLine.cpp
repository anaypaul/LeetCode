class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        if(c[0][0] == c[1][0]){ //undefined slope case. x1 == x2
            for(int i = 2; i<c.size(); i++){
                if(c[0][0] != c[i][0]){
                    return false;
                }
            }
            return true;
        }
        double slope =(c[0][1] - c[1][1])/(c[0][0] - c[1][0]);
        for(int i = 2; i<c.size(); i++){
            
            if(c[0][0] == c[i][0]){
                return false;
            }
            if((double)(c[0][1] - c[i][1])/(c[0][0] - c[i][0]) != slope){
                
                return false;
            }
        }
        return true;
    }
};