class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' ||ch=='O' || ch=='U';
    }
    string toGoatLatin(string S) {
        stringstream ss(S);
        vector<string> v;
        do{
            string word;
            ss >> word;
            v.push_back(word);
        }while(ss);
        string res = "";
        for(int i = 0; i<v.size(); i++){
            int c = i+1;
            string temp = "";
            if(isVowel(v[i][0])){
                temp = temp + "ma";
                for(int j = v[i].size()-1; j>=0; j--){
                    temp = v[i][j] + temp;
                }
                while(c--){
                    temp = temp + "a";
                }
            }else{
                temp = temp + v[i][0] + "ma";
                for(int j = v[i].size()-1; j>=1; j--){
                    temp = v[i][j] + temp;
                }
                while(c--){
                    temp = temp + "a";
                }
            }
            if(i== 0){
                res = res + temp;
            }else if(i == v.size()-1){
                break;
            }else{
                res = res + " "+ temp;
            }
            
        }
        return res;
    }
};