#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int longestValidParentheses(string s){
    string rev = "";
    for(int i = s.length()-1; i>=0;i--){
        rev = rev +  s[i];
    }
    //1st pass
    int i = 0;
    int j = 0;
    int max1 = 0;
    int count = 0;
    while(j<s.length()){
        if(s[j]=='('){
            count++;
        }else if(s[j]==')'){
            count--;
        }
        if(count==0){
            max1 = max(max1, j-i+1);
        }else if(count <0){
            count = 0;
            i = j+1;
        }
        j = j + 1;
    }

    i = 0;
    j = 0;
    int max2 = 0;
    count = 0;
    while(j < rev.length()){
        if(rev[j]==')'){
            count++;
        }else if(rev[j]=='('){
            count--;
        }
        if( count==0){
            max2 = max(max2, j-i+1);
        }else if(count < 0){
            i = j + 1;
            count = 0;
        }
        j = j + 1;
    }
    
    return max(max1,max2);
}
int main(){
    string s;
    cin>>s;
    int l = longestValidParentheses(s);
    cout<<"longestValidParentheses : "<<l<<endl;
    return 0;
}