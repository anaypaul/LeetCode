class Solution {
public:
    
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        int n = dominoes.size();
        map<pair<int,int> , int> m;
        for(int i = 0;i<n ; i++){
            int x = min(dominoes[i][0], dominoes[i][1]);
            int y = max(dominoes[i][0], dominoes[i][1]);
            pair<int, int> p = {x,y};
            
            if(m.find(p) == m.end()){
                m.insert(make_pair(p, 1));
            }else{
                res += m[p];
                m[p]++;
            }
        }
        return res;
    }
};