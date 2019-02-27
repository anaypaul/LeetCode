class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        int index_x = -1;
        int index_y = -1;
        //find position of rook
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                if(board[i][j] == 'R'){
                    index_x = i;
                    index_y = j;
                }
            }
        }
        cout<<index_x<<" "<<index_y<<endl;
        //check upward
        for(int i = index_y-1;i>=0;i--){
            if(board[index_x][i]>='A' && board[index_x][i] <='Z'){
                break;
            }
            if(board[index_x][i] == 'p'){
                ans++;
                break;
            }
        }
        //check downward
        for(int i = index_y+1 ;i<board.size();i++){
            if(board[index_x][i]>='A' && board[index_x][i] <='Z'){
                break;
            }
            if(board[index_x][i] == 'p'){
                ans++;
                break;
            }
        }
        //check on right;
        for(int i = index_x+1 ; i< board.size(); i++){
            if(board[i][index_y] >='A' && board[i][index_y]<='Z'){
                break;
            }
            if(board[i][index_y] == 'p'){
                ans++;
                break;
            }
        }
        //check on left;
        for(int i=index_x-1;i>=0  ;i--){
            if(board[i][index_y] >='A' && board[i][index_y]<='Z'){
                break;
            }
            if(board[i][index_y] == 'p'){
                ans++;
                break;
            }
        }
        return ans;
    }
};