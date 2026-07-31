class Solution {
   int helper(int currIdx, int buy, vector<int>& prices, int n, vector<vector<int>> &dp) {
        // Base case: If we run out of days, we can't make any more profit
        if (currIdx >= n) return 0;
        
        // Return cached result
        if (dp[currIdx][buy] != -1) return dp[currIdx][buy];
        
        if (buy == 1) {
            // Choice 1: Buy today (subtract price) and look to sell next day
            int pick = -prices[currIdx] + helper(currIdx + 1, 0, prices, n, dp);
            // Choice 2: Skip today
            int notPick = helper(currIdx + 1, 1, prices, n, dp);
            
            return dp[currIdx][buy] = max(pick, notPick);
        } else {
            // Choice 1: Sell today (add price) and jump 2 days ahead due to COOLDOWN
            int pick = prices[currIdx] + helper(currIdx + 2, 1, prices, n, dp);
            // Choice 2: Skip today
            int notPick = helper(currIdx + 1, 0, prices, n, dp);
            
            return dp[currIdx][buy] = max(pick, notPick);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp table of size n x 2 (0 for sell state, 1 for buy state)
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, n, dp);
    }
};
