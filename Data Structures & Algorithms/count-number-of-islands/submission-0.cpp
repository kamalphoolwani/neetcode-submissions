class Solution {
    vector<pair<int,int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, int &n, int &m, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        vis[i][j] = true;

        for(auto &d : dir){
            int nI = i + d.first;
            int nJ = j + d.second;
            if(nI>=0 and nI<n and nJ>=0 and nJ<m and grid[nI][nJ]=='1' and vis[nI][nJ]==false)
                dfs(nI, nJ, n, m, grid, vis);
        }

        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int numIslands = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]=='1' and vis[i][j]==false){
                    numIslands++;
                    dfs(i, j, n, m, grid, vis);
                }
            }
        }

        return numIslands;
    }
};
