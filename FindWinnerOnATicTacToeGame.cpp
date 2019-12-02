class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> rows(3, 0);
        vector<int> cols(3, 0);
        int primary = 0;
        int secondary = 0;
        int player = 1; // player A 
        for(auto x : moves){
            int add = player == 1 ? 1 : -1;
            int row = x[0];
            int col = x[1];
            rows[row] += add;
            cols[col] += add;
            if(row == col){
                primary += add;
            }
            if(row + col == 2){
                secondary += add;
            }
            if(abs(rows[row]) == 3 || abs(cols[col]) == 3 || abs(primary) == 3 || abs(secondary) == 3){
                if(player == 1){
                    return "A";
                }else{
                    return "B";
                }
            }
            if(player == 1){
                player = 2;
            }else{
                player = 1;
            }
        }
        if(moves.size() == 3 * 3){
            return "Draw";
        }
        return "Pending";
    }
};