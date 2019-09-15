int res = INT_MAX;
        map<char, int> m {
            {'b' , 0},
            {'a' , 0},
            {'l' , 0},
            {'o' , 0},
            {'n' , 0},
        };
        for(int i = 0;i<text.length();i++){
            if(m.find(text[i]) != m.end()){
                m[text[i]] += 1;
            }
        }
        m['l'] = m['l']/2;
        m['o'] = m['o']/2;
        for(auto xx : m){
            res = min(res, xx.second);
        }
        return res==INT_MAX ? 0 : res;
    }
};