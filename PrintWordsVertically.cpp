class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        string temp;
        vector<string> v;
        int maxLen = 0;
        while(ss>>temp){
            v.push_back(temp);
            maxLen = max(maxLen, (int)temp.length());
        }
        
        vector<string> res(maxLen, "");
        for(auto each : v){
            for(int i = 0; i<res.size(); i++){
                if(i < each.size()){
                    res[i] += each[i];
                }else{
                    res[i] += " ";
                }
            }
        }
        for(int i = 0; i<res.size(); i++){
            string st = res[i];
            if(st[st.size()-1] == ' '){
                int x = 0;
                int j = st.size()-1;
                while(st[j] == ' '){
                    j--;
                    x++;
                }
                res[i] = st.substr(0, st.size()-x);
            }
            
        }
        return res;
    }
};