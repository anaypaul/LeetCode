#include<string.h>
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        map<string, int> m;
        for(int i = 0;i<cpdomains.size();i++){
            int count = 0;
            string c_string = "";
            int j;
            for( j = 0;cpdomains[i][j]!=' ';j++){
                
                c_string += cpdomains[i][j];
            }
            count = stoi(c_string);
            cout<<"count : "<<count<<endl;
            j++;
            int c = 0;
            string s1 = "";
            string s2 = "";
            string s3 = "";
            for(int k = j;k<cpdomains[i].length();k++){
                if(cpdomains[i][k] !='.'){
                    if(c==0){
                        s1 += cpdomains[i][k];
                    }
                    else if(c==1){
                        s1 += cpdomains[i][k];
                        s2 += cpdomains[i][k];
                    }else if(c==2){
                        s1 += cpdomains[i][k];
                        s2 += cpdomains[i][k];
                        s3 += cpdomains[i][k];
                    }
                }else{
                    if(c==0){
                        s1 += cpdomains[i][k];
                        c++;
                    }else if(c==1){
                        s1 += cpdomains[i][k];
                        s2 += cpdomains[i][k];
                        c++;
                    }
                }
                
               
            }
            cout<<s1<<" "<<s2<<" "<<s3<<endl;
            if(s1 != "" ){
                if(m.find(s1) == m.end()){
                    m[s1] = count;
                }else{
                    m[s1] += count;
                }
            }
            if(s2 != "" ){
                if(m.find(s2) == m.end()){
                    m[s2] = count;
                }else{
                    m[s2] += count;
                }
            }
            if(s3 != "" ){
                if(m.find(s3) == m.end()){
                    m[s3] = count;
                }else{
                    m[s3] += count;
                }
            }
            cout<<endl;
        }
        
        for(auto x : m){
            string sa = to_string(x.second) + " "+ x.first;
            res.push_back(sa);
        }
        return res;
    }
};