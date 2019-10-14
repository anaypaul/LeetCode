class Solution {
public:
    char getInt(int n){
        if(n==0){
            return '0';
        }else if(n==1){
            return '1';
        }else if(n==2){
            return '2';
        }else if(n==3){
            return '3';
        }else if(n==4){
            return '4';
        }else if(n==5){
            return '5';
        }else if(n==6){
            return '6';
        }else if(n==7){
            return '7';
        }else if(n==8){
            return '8';
        }else if(n==9){
            return '9';
        }
        return -1;
    }
    string getString(int n){
        string res = "";
        while(n > 0){
            res = getInt(n%10) + res;
            n = n/10;
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<int>> um;
        vector<int> hash(26, 0);
        for(int i = 0; i<strs.size(); i++){
            for(auto y : strs[i]){
                hash[y-'a']++;
            }
            string xx = "";
            for(auto val : hash){
                xx = xx + getString(val) + ":";
            }
            for(int i = 0; i<hash.size(); i++){
                xx = xx + getString(hash[i]) + ":";
                hash[i] = 0;
            }
            um[xx].push_back(i);
        }
        
        for(auto x : um){
            vector<string> temp;
            for(auto y : x.second){
                temp.push_back(strs[y]);
            }
            res.push_back(temp);
        }
        return res;
    }
};