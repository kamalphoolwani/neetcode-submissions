class Solution {
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int func(int x, int y, int &n, int &m, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        int ans = 0;

        if(dp[x][y]!=-1)
            return dp[x][y];
        for(int d = 0; d<4; d++){
            int nX = x + dir[d].first;
            int nY = y + dir[d].second;
            if(nX<0 || nY<0 || nX>=n || nY>=m || matrix[x][y] <= matrix[nX][nY])
                continue;
            ans = max(ans, 1 + func(nX, nY, n, m, matrix, dp));
        }

        return dp[x][y] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                    ans = max(ans, func(i, j, n, m, matrix, dp));
            }
        }
        return ans+1;        
    }
};
