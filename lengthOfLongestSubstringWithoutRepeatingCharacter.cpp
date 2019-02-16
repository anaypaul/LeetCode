#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
int LSWR(string s){
    //naive approach
    int ans  = -1;
    for(int len = 1;len<=s.length();len++){
        for(int start = 0;start<s.length()-len+1;start++){
            string temp="";
            int curr_len = 0;
            for(int j = start;j<start+len;j++){
                temp = temp+s[j];
            }
            curr_len = fun(temp);
            if(ans < curr_len){
                ans = curr_len;
            }
        }
    }
    return ans;
}
int lengthOfLongestSubstring(string s){
    // O(n) approach using maps.
    int start = 0;
    map<char, int> mymap ;
    int max_length = 0;
    int end = 0;
    while(end <s.length()){
        if(mymap.find(s[end]) == mymap.end() ){
            mymap.insert(make_pair(s[end], end));
        }else{
            start = max(start, mymap[s[end]]+1);
            mymap[s[end]] = end;
        }
        max_length = max(max_length, end-start + 1);
        end++;
    }
    return max_length;
}
int main(){
    string s;
    cin>>s;
    cout<<"length of string = "<<s.length()<<endl;
    int x = lengthOfLongestSubstring(s);
    cout<<"Length of the longest Substring without repeating character : "<<x<<endl;
    return 0;
}

