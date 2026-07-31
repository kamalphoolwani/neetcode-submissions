class Solution {
    // bool isValid(int r, int c, vector<vector<char>>& board){
    //     // checkRow
    //     for(int col = 0; col<9; col++){
    //         if(col != c and board[r][col] == board[r][c])
    //             return false;
    //     }

    //     for(int row = 0; row<9; row++){
    //         if(row!= r and board[row][c] == board[r][c])
    //             return false;
    //     }

    //     for(int i = 0; i<3; i++){
    //         int currR = (r/3)*3 + i;
    //         for(int j = 0; j<3; j++){
    //             int currC = (c/3)*3 + j;
    //             if(currR!= r and currC!= c and board[currR][currC] == board[r][c])
    //                 return false;
    //         }
    //     }
    //     return true;
    // }
    // bool func(int r, int c, vector<vector<char>>& board){
    //     if(c==9){
    //         c=0;
    //         r++;
    //     }
    //     if(r==9)
    //         return true;
    //     if(board[r][c]!= '.')
    //         return func(r, c+1, board);
        
    //     for(char ch = '1'; ch<='9'; ch++){
    //         board[r][c] = ch;
    //         if(isValid(r, c, board)){
    //             if(func(r, c+1, board))
    //                 return true;
    //         }
    //         board[r][c] =  '.';
    //     }
    //     return false;
    // }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                // Skip empty cells
                if (board[r][c] == '.') continue;

                // Convert char digit ('1'-'9') to an index (0-8)
                int num = board[r][c] - '1';
                int boxIdx = (r / 3) * 3 + (c / 3);

                // If we've seen this number in this row, col, or box before -> Invalid!
                if (rows[r][num] || cols[c][num] || boxes[boxIdx][num]) {
                    return false;
                }

                // Mark this number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIdx][num] = true;
            }
        }

        return true;
    }
};
