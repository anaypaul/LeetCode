class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
    string getString(vector<vector<int>>& board){
        string res = "";
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                res += to_string(board[i][j]);
            }
        }
        return res;
    }
    pair<int,int> get2D(int idx, int n , int m){
        return {idx / m, idx % m};
    }
    int get1D(int i, int j, int n, int m){
        return i * m + j;
    }
    int findZero(string s){
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '0'){
                return i;
            }
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        std::ios_base::sync_with_stdio(false);
        cout.tie(0);
        cout.tie(0);
        int res = 0;
        int n = board.size();
        int m = board[0].size();
        string target = "";
        for(int i = 1; i<= (n * m)-1; i++){
            target += to_string(i);
        }
        target += to_string(0);
        string start = getString(board);
        int depth = 0;
        if(start.compare(target) == 0){
            return depth;
        }
        unordered_set<string> vis;
        queue<string> q;
        q.push(start);
        vis.insert(start);
        while(!q.empty()){
            int x = q.size();
            for(int i = 0; i<x; i++){
                auto curr = q.front();
                q.pop();
                if(curr.compare(target) == 0){
                    return depth;
                }
                int oldIndex = findZero(curr);
                pair<int, int> p = get2D(oldIndex, n, m);
                for(int idx = 0; idx<4; idx++){
                    int nexti = p.first + dx[idx];
                    int nextj = p.second + dy[idx];
                    if(check(nexti, nextj, n, m)){
                        string t = curr;
                        int newIdx = get1D(nexti, nextj, n, m);
                        char temp = t[oldIndex];
                        t[oldIndex] = t[newIdx];
                        t[newIdx] = temp;
                        if(vis.find(t) == vis.end()){
                            q.push(t);
                            vis.insert(t);
                        }
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};