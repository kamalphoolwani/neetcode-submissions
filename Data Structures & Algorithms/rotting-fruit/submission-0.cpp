class Solution {
    int dX[4] = {1, -1, 0, 0};
    int dY[4] = {0, 0, 1, -1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
                else if(grid[i][j]==1)
                    ++fresh;
            }
        }

        int time = 0;
        while(!q.empty()){
            int qSz = q.size();
            bool found = false;
            for(int i = 0; i<qSz; i++){
                int cX = q.front().first;
                int cY = q.front().second;
                q.pop();

                for(int d = 0; d<4; d++){
                    int nX = cX + dX[d];
                    int nY = cY + dY[d];

                    if(nX>=0 && nX<n and nY>=0 && nY<m and grid[nX][nY]==1){
                        grid[nX][nY] = 2;
                        q.push({nX, nY});
                        found = true;
                        --fresh;
                    }
                }
            }
            time = time + found;
        }

        return (fresh==0)?time:-1;
    }
};
