class Solution {
    void dfs(int r, int c, int prevHeight, vector<vector<int>>& heights, vector<vector<bool>>& reachable) {
        int n = heights.size();
        int m = heights[0].size();

        // 1. Check bounds
        // 2. Already visited?
        // 3. Height check: Reverse flow means next height MUST be >= previous
        if (r < 0 || r >= n || c < 0 || c >= m || reachable[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        reachable[r][c] = true;

        dfs(r + 1, c, heights[r][c], heights, reachable);
        dfs(r - 1, c, heights[r][c], heights, reachable);
        dfs(r, c + 1, heights[r][c], heights, reachable);
        dfs(r, c - 1, heights[r][c], heights, reachable);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Start DFS from Top/Bottom rows
        for (int j = 0; j < m; j++) {
            dfs(0, j, heights[0][j], heights, pacific);     // Pacific (Top)
            dfs(n - 1, j, heights[n - 1][j], heights, atlantic); // Atlantic (Bottom)
        }

        // Start DFS from Left/Right columns
        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights[i][0], heights, pacific);     // Pacific (Left)
            dfs(i, m - 1, heights[i][m - 1], heights, atlantic); // Atlantic (Right)
        }

        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};