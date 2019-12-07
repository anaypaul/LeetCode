class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>> mat(15, vector<int>(8, 0));
        vector<int> curr(cells.begin(), cells.end());
        for(int i = 0;i<mat.size();i++){
            for(int j= 1; j<7;j++){
                mat[i][j] = curr[j-1] == curr[j+1] ? 1 : 0;
            }
            curr.clear();
            for(int j = 0;j<8;j++){
                curr.push_back(mat[i][j]);
            }
        }
        return mat[(N-1)%14];
    }
};

//Approach 2
class Solution {
public:
    string encode(vector<int> v){
        string res = "";
        for(int i = 0; i<v.size(); i++){
            res += to_string(v[i]) + "#";
        }
        return res;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> mat(0, vector<int>(8, 0));
        unordered_set<string> myset;
        while(true){
            vector<int> next(8,0);
            for(int i = 1; i<7; i++){
                if(cells[i-1] == cells[i+1]){
                    next[i] = 1;
                }else{
                    next[i] = 0;
                }
            }
            string xx = encode(next);
            if(myset.find(xx) == myset.end()){
                myset.insert(xx);
                mat.push_back(next);
                cells = next;
            }else{
                break;
            }
        }
        return mat[(N-1)%mat.size()];
    }
};