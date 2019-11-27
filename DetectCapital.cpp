class Solution {
public:
    bool detectCapitalUse(string word) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(word.size()== 1){
            return true;
        }
        int n = word.size();
        if(isupper(word[0]) && isupper(word[n-1])){
            for(int i = 0; i<n; i++){
                if(!isupper(word[i])){
                    return false;
                }
            }
            return true;
        }
        else if(isupper(word[0]) && !isupper(word[n-1])){
            for(int i = 1; i<n; i++){
                if(isupper(word[i])){
                    return false;
                }
            }
            return true;
        }
        else if(islower(word[0]) && islower(word[n-1])){
            for(int i = 0; i<n; i++){
                if(isupper(word[i])){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};