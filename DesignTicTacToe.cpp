class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<int> rowTracker;
    vector<int> colTracker;
    int primary;
    int secondary;
    int total;
    TicTacToe(int n):rowTracker(n), colTracker(n), primary(0), secondary(0), total(n) {}
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        primary += row == col ? add : 0;
        secondary += row + col == total-1 ? add : 0;
        rowTracker[row] += add;
        colTracker[col] += add;
        if(abs(rowTracker[row]) == total || abs(colTracker[col]) == total || abs(primary) == total || abs(secondary) == total){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */