class Solution {
    int func(int x, int y, vector<vector<int>> &dp){
        if(x<0 || y<0)
            return 0;
        if(x==0 and y==0)
            return 1;
        if(dp[x][y]!=-1)
            return dp[x][y];
        int left = func(x-1, y, dp);
        int bottom = func(x, y-1, dp);

        return dp[x][y] = left + bottom;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m-1, n-1, dp);
    }
};
