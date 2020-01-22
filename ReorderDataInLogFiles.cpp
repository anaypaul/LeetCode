class Solution {
public:
    static bool mycmp(const string &a, const string& b){
        string contenta = a.substr(a.find(' ') + 1);
        string contentb = b.substr(b.find(' ') + 1);
        if(isdigit(contenta[0])){
            return false;
        }else if(isdigit(contentb[0])){
            return true;
        }
        else if(contenta.compare(contentb) == 0){
            string ida = a.substr(0, a.find(' '));
            string idb = b.substr(0, b.find(' '));
            return ida.compare(idb)<0;
        }
        return contenta.compare(contentb) < 0;
    }

vector<string> reorderLogFiles(vector<string> &logs) {
    stable_sort(logs.begin(), logs.end(), mycmp);
    return logs;
    }

};

//Approach 2
class Solution {
public:
    static bool mycmp(pair<string, string> p1, pair<string, string> p2){
        if(p1.first.compare(p2.first) < 0){
            return true;
        }else if(p1.first.compare(p2.first) == 0){
            if(p1.second.compare(p2.second) < 0){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        vector<pair<string, string>> letterlogs;
        vector<string> digitlogs;
        for(auto log : logs){
            int pos = log.find_first_of(' ');
            string id = log.substr(0, pos);
            string ll = log.substr(pos+1);
            if(isalpha(ll[0])){
                letterlogs.push_back(make_pair(ll, id));
            }else{
                digitlogs.push_back(log);
            } 
        }
        sort(letterlogs.begin(), letterlogs.end(), mycmp);
        for(auto each : letterlogs){
            res.push_back(each.second + " " + each.first);
        }
        for(auto each : digitlogs){
            res.push_back(each);
        }
        return res;
    }
};       
        
