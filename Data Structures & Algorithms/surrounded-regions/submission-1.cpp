class Solution {
    int dX[4] = {1, -1, 0, 0};
    int dY[4] = {0, 0, 1, -1};
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;

        for(int j=0; j<m; j++){
            if(board[0][j]=='O'){
                q.push({0, j});
                board[0][j] = 'Y';
            }
            if(board[n-1][j]=='O'){
                q.push({n-1, j});
                board[n-1][j] = 'Y';
            }
        }

        for(int i=1; i<=n-2; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'Y';
            }
            if(board[i][m-1]=='O'){
                q.push({i, m-1});
                board[i][m-1] = 'Y';
            }
        }
        
        while(!q.empty()){
            int cX = q.front().first;
            int cY = q.front().second;
            q.pop();

            for(int d = 0; d<4; d++){
                int nX = cX + dX[d];
                int nY = cY + dY[d];

                if(nX>=0 and nX<n and nY>=0 and nY<m and board[nX][nY]=='O'){
                    board[nX][nY] = 'Y';
                    q.push({nX, nY});
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='Y')
                    board[i][j] = 'O';
                else if(board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
    }
};
