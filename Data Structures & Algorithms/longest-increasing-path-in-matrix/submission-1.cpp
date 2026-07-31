class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 0 || m == 0) return 0;

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> outdegree(n, vector<int>(m, 0));

        // Step 1: Calculate out-degrees for every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int d = 0; d < 4; d++) {
                    int nX = i + dir[d].first;
                    int nY = j + dir[d].second;
                    if (nX >= 0 && nY >= 0 && nX < n && nY < m && matrix[nX][nY] > matrix[i][j]) {
                        outdegree[i][j]++;
                    }
                }
            }
        }

        // Step 2: Queue all cells with 0 out-degree (local peaks)
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (outdegree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Step 3: Tabulate layer by layer (BFS / Kahn's Algorithm style)
        int layers = 0;
        while (!q.empty()) {
            int size = q.size();
            layers++; // Each level of the queue represents an increase in path length
            
            for (int k = 0; k < size; k++) {
                auto [x, y] = q.front();
                q.pop();

                // Look for smaller neighbors that could step INTO the current cell
                for (int d = 0; d < 4; d++) {
                    int nX = x + dir[d].first;
                    int nY = y + dir[d].second;

                    if (nX >= 0 && nY >= 0 && nX < n && nY < m && matrix[nX][nY] < matrix[x][y]) {
                        outdegree[nX][nY]--;
                        if (outdegree[nX][nY] == 0) {
                            q.push({nX, nY});
                        }
                    }
                }
            }
        }

        return layers;
    }
};