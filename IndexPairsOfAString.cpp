#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > indexPairs(string text, vector<string>& words){
    vector<vector<int> > pairs;
    for(string x : words){
        cout<<x<<"***"<<endl;
        size_t t = text.find(x);
        while(t !=string::npos){
            cout<<" occurrence of "<<x<<" at : "<< t;
            cout<<" "<<t + x.length()-1<<endl;
            t = text.find(x, t + 1);
            vector<int> vv;
            vv.push_back((int)t);
            vv.push_back((int)t+x.length()-1);
            pairs.push_back(vv);
            vv.clear();
        }
    }
    for(vector<int> d : pairs){
        cout<<d[0]<<" "<<d[1]<<endl;
    }
    return pairs;
}
int main(){
    string txt = "ababa";
    string words[] = {"ab","aba"};
    // string txt = "thestoryofleetcodeandmestory";
    // string words[] = {"story","fleet","leetcode"};
    vector<string> wlist(words, words + sizeof(words)/sizeof(words[0]));
    vector<vector<int> > answer= indexPairs(txt, wlist);
    for(vector<int> d : answer){
        cout<<d[0]<<" "<<d[1]<<endl;
    }
    return 0;
}


//New Approach
class Solution {
public:
    vector<vector<int>> indexPairs(string s, vector<string>& words) {
        set<string> A(words.begin(), words.end());
        vector<vector<int>> res;
        int n = s.length();
        for(int i = 0;i<n ; i++){
            for(int j = i + 1; j<= n ; j++){
                if(A.count(s.substr(i, j-i))){
                    res.push_back({i , j - 1});
                }
            }
        }
        return res;
    }
};