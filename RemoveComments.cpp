class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool blockOpen = false;
        bool singleOpen = false;
        vector<string> res;
        string temp = "";
        for(int i = 0; i<source.size(); i++){
            if(blockOpen == false){
                temp = "";
            }
            for(int j = 0; j<source[i].size(); ){
                
                if(blockOpen && j+1 < source[i].size() && source[i][j] == '*' && source[i][j+1] == '/'){
                    // cout<<"closing block comment"<<endl;
                    blockOpen = false;
                    j = j + 2;
                }
                else if(blockOpen){
                    // cout<<"ignoring "<<source[i][j]<<endl;
                    j++;
                    continue;
                }
                else if(singleOpen){
                    break;
                }
                
                else if(!blockOpen && j+1 < source[i].size() &&source[i][j] == '/' && source[i][j+1] == '*'){
                    // cout<<"starting block comment"<<endl;
                    blockOpen = true;
                    j = j + 2;
                }
                else if(!singleOpen && j+1 < source[i].size() && source[i][j] == '/' && source[i][j+1] == '/'){
                    // cout<<"starting single line comment"<<endl;
                    singleOpen = true;
                    j = j + 2;
                }
                else if(!blockOpen && !singleOpen && j< source[i].size()){
                    // cout<<"including in temp"<<source[i][j]<<endl;
                    temp += source[i][j];
                    j++;
                }
                
                
            }
            singleOpen = false;
            // cout<<"temp :"<<temp<<endl;
            if(temp.empty() == false && blockOpen == false){
                res.push_back(temp);
                temp = "";            
            }
        }
        return res;
    }
};