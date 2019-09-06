class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        int rook_i = -1;
        int rook_j = -1;
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == 'R'){
                    rook_i = i;
                    rook_j = j;
                    break;
                }
            }
            if(rook_i != -1){
                break;
            }
        }
        
        //toward right
        for(int j = rook_j ; j<board[0].size()-1;j++){
            if(board[rook_i][j+1] == '.'){
                continue;
            }else if(board[rook_i][j+1] == 'B'){
                break;
            }else if(board[rook_i][j+1] == 'p'){
                count++;
                break;
            }
        }
        //towards left
        for(int j = rook_j;j>=1 ;j--){
            if(board[rook_i][j-1] == '.'){
                continue;
            }else if(board[rook_i][j-1] == 'B'){
                break;
            }else if(board[rook_i][j-1] == 'p'){
                count++;
                break;
            }
        }
        
        //upwards
        for(int i = rook_i;i>=1 ;i--){
            if(board[i-1][rook_j] == '.'){
                continue;
            }else if(board[i-1][rook_j] == 'B'){
                break;
            }else if(board[i-1][rook_j] == 'p'){
                count++;
                break;
            }
        }
        
        
        //downwards
        for(int i = rook_i;i<board.size()-1;i++){
            if(board[i+1][rook_j] == '.'){
                continue;
            }else if(board[i+1][rook_j] == 'B'){
                break;
            }else if(board[i+1][rook_j] == 'p'){
                count++;
                break;
            }
        }
        return count;
    }
};