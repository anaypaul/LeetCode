class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        int n = 8; int m = 8;
        unordered_set<string> us;
        for(auto x : queens){
            string s = to_string(x[0]) + ":" + to_string(x[1]);
            us.insert(s);
        }
        int i = king[0];
        for(int j = king[1]; j>=0; j--){
            string s = to_string(i) + ":" + to_string(j);
            if(us.find(s) != us.end()){
                res.push_back({i,j});
                break;
            }
        }
        
        for(int j = king[1]; j<m; j++){
            string s= to_string(i) + ":" + to_string(j);
            if(us.find(s) != us.end()){
                res.push_back({i,j});
                break;
            }
        }
        
        int j = king[1];
        for(int i = king[0]; i>=0 ; i--){
            string s = to_string(i) + ":" + to_string(j);
            if(us.find(s) != us.end()){
                res.push_back({i,j});
                break;
            }
        }
        
        for(int i = king[0]; i<n;i++){
            string s = to_string(i) + ":" + to_string(j);
            if(us.find(s) != us.end()){
                res.push_back({i,j});
                break;
            }
        }
        
        i = king[0];
        j = king[1];
        for(; i<n && j<m; i++, j++){
            string s = to_string(i) + ":" + to_string(j);
            if(us.find(s) != us.end()){
                res.push_back({i,j});
                break;
            }
        }
        i = king[0];
        j = king[1];
        for(; i>=0 && j>=0; i--, j--){
            string s = to_string(i) + ":" + to_string(j);
            if(us.find(s) != us.end()){
                res.push_back({i,j});
                break;
            }
        }
        i = king[0];
        j = king[1];
        for(; i>=0 && j<m; i--, j++){
            string s = to_string(i) + ":" + to_string(j);
            if(us.find(s) != us.end()){
                res.push_back({i,j});
                break;
            }
        }
        i = king[0];
        j = king[1];
        for(; i<m && j>=0 ; i++, j--){
            string s = to_string(i) + ":" + to_string(j);
            if(us.find(s) != us.end()){
                res.push_back({i,j});
                break;
            }
        }
        return res;
    }
};