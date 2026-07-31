class Solution {
    int helper(int currIdx, int prevIdx, vector<int>& prices, int &n,  vector<vector<int>> &dp){
        if(currIdx>=n)
            return 0;
        if(dp[currIdx][prevIdx+1]!=-1)
            return dp[currIdx][prevIdx+1];
        if(prevIdx == -1){
            return dp[currIdx][prevIdx+1]=max(helper(currIdx+1, currIdx, prices, n, dp), helper(currIdx+1, prevIdx, prices, n, dp));
        }
        return dp[currIdx][prevIdx+1]= max((prices[currIdx] - prices[prevIdx] + helper(currIdx+2, -1, prices, n, dp)), helper(currIdx+1, prevIdx, prices, n, dp));
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helper(0, -1, prices, n, dp);
    }
};
