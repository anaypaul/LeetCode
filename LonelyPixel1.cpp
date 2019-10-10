class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& pic) {
        int n = pic.size();
        int m = pic[0].size();
        unordered_map<int,int> rows;
        unordered_map<int,int> cols;
        vector<pair<int,int>> v;
        for(int i= 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(pic[i][j] == 'B'){
                    rows[i]++;
                    cols[j]++;
                    v.push_back(make_pair(i,j));
                }
            }
        }
        int res=0;
        for(auto x : v){
            if(rows[x.first] == 1 && cols[x.second] == 1){
                res++;
            }
        }
        return res;
    }
};