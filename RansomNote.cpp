class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char, int> mag_m;
        for(auto x : magazine){
            mag_m[x]++;
        }
        unordered_map<char, int> ransom_m;
        for(auto x : ransomNote){
            ransom_m[x]++;
        }
        for(int i = 0; i<ransomNote.size(); i++){
            if(mag_m.find(ransomNote[i]) != mag_m.end()){
                if(mag_m[ransomNote[i]] >= ransom_m[ransomNote[i]]){
                    continue;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};