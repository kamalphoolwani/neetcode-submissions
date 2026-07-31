class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    const int INF = 2147483647;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            } 
        }
        while(!q.empty()){
            int qSz = q.size();
            for(int i = 0; i<qSz; i++){
                int currX = q.front().first;
                int currY = q.front().second;
                q.pop();
                

                for(int d = 0; d<4; d++){
                    int nX = currX + dx[d];
                    int nY = currY + dy[d];
                    if(nX>=0 and nX<n and nY>=0 and nY<m and grid[nX][nY]==INF){
                        q.push({nX, nY});
                        grid[nX][nY] =  grid[currX][currY] + 1;
                    }
                }
            }
        }
        return;
    }
};
