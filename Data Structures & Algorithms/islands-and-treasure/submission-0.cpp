class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({i, j});
                    vis[i][j] = true;
                }
            } 
        }
        int steps = 0;
        while(!q.empty()){
            int qSz = q.size();
            for(int i = 0; i<qSz; i++){
                int currX = q.front().first;
                int currY = q.front().second;
                q.pop();
                grid[currX][currY] = steps;

                for(int d = 0; d<4; d++){
                    int nX = currX + dx[d];
                    int nY = currY + dy[d];
                    if(nX>=0 and nX<n and nY>=0 and nY<m and grid[nX][nY]!=-1 and vis[nX][nY]==false){
                        q.push({nX, nY});
                        vis[nX][nY] = true;
                    }
                }
            }
            steps++;
        }
        return;
    }
};
