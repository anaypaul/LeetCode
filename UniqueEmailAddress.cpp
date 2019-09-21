class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(int i = 0; i<emails.size(); i++){
            string email = emails[i];
            string x ="";
            bool domain = false;
            for(int j = 0; j<email.length();j++){
                if(email[j] == '+' && !domain){
                    while(email[j]!= '@'){
                        j++;
                        domain = true;
                    }
                }
                if(email[j] == '@'){
                    domain= true;
                }
                if(email[j] == '.' && !domain){
                    continue;
                }
                if(email[j] == '.' && domain){
                    x = x+ '.';
                    continue;
                }
                x = x+ email[j];
            }
            s.insert(x);
        }
        return s.size();
    }
};