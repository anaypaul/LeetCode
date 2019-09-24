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