class Solution {
    int func(int idx, int n, vector<vector<int>> &dp){
        if(n==0)
            return 0;
        if(idx==1){
            return n;
        }
        if(dp[idx][n] != -1)
            return dp[idx][n];
        int pick = INT_MAX, notPick = INT_MAX;
        if(idx * idx <= n){
            pick = 1 + func(idx, n - (idx*idx), dp);
        }
        notPick = func(idx-1, n, dp);

        return dp[idx][n] = min(pick, notPick);
    }
public:
    int numSquares(int n) {
        vector<vector<int>> dp(101, vector<int>(n+1, -1));
        return func(100, n, dp);
    }

};