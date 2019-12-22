class Solution {
public:
    bool check(vector<int> next){
        for(auto x : next){
            if(x == 1){
                return true;
            }
        }
        return false;
    }
    bool noKeys(vector<int> v){
        for(auto x : v){
            if(x == 1){
                return false;
            }
        }
        return true;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        if(initialBoxes.size() == 0){
            return 0;
        }
        int res = 0;
        vector<int> next(1001, 0);
        for(int x : initialBoxes){
            next[x] = 1;
        }
        int checklater = 0;
        vector<int> mykeys(1001, 0);
        while(check(next)){
            bool flag = false;
            for(int i = 0; i<next.size(); i++){
                if(next[i] == 1){
                    flag = true;
                    if(status[i] == 1 || mykeys[i] == 1){
                        res += candies[i];
                        next[i] = 0;
                        mykeys[i] = 0;
                        checklater = 0;
                    }else{
                        checklater++;
                        continue;
                    }
                    
                    for(auto k : keys[i]){
                        mykeys[k] = 1;
                    }
                    
                    for(auto n : containedBoxes[i]){
                        next[n] = 1;
                    }
                }
                if(checklater>1000){
                    return res;
                }
            }
            if(flag == false && noKeys(mykeys)){
                return res;
            }
        }
        return res;
    }
};