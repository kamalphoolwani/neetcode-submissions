class Solution {
    int func(int n, vector<int> &dp){
        if(n<2)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        int maxProd = 1;
        for(int k = 2; k<=n; k++){
            maxProd = max(maxProd, max(k*(n-k), k* func(n-k, dp)));
        }

        return dp[n] = maxProd;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return func(n, dp);
    }
};