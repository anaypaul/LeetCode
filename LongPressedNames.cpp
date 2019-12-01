class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int idx = 0;
        int i = 0;
        for( i = 0; idx<name.size() && i<typed.size(); ){
            if(name[idx] == typed[i]){
                char curr = name[idx];
                while(idx<name.size() && i<typed.size() && name[idx] == typed[i] && name[idx] == curr){
                    idx++;
                    i++;
                }
                while(i<typed.size() && curr == typed[i]){
                    i++;
                }
            }else{
                return false;
            }
        }
        return idx == name.size() && i == typed.size() ;
    }
};