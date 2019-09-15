class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> m ;
        for(int i = 0;i<secret.length();i++){
            if(secret[i] == guess[i]){
                bulls++;
            }else{
                m[secret[i]] += 1;
            }
        }
        for(int i = 0;i<secret.length(); i++){
            if(guess[i] != secret[i] && m.count(guess[i]) > 0){
                if(--m[guess[i]] == 0){
                    m.erase(guess[i]);
                }
                cows++;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
        
    }
};