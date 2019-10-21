class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> change;
        change[5] = 0;
        change[10] = 0;
        change[20] = 0;
        int i = 0;
        for(; i<bills.size(); i++){
            int ret = bills[i]-5;
            if(ret == 5){
                if(change[5]>=1){
                    change[5]--;
                }
                else{
                    return false;
                }
            }else if(ret == 15){
                if((change[10]>=1 && change[5]>=1)){
                    change[5]--;
                    change[10]--;
                }else if(change[5]>=3){
                    change[5] -= 3;
                }else{
                    return false;
                }
            }
            change[bills[i]]++;
        }
        return true;
        
    }
};