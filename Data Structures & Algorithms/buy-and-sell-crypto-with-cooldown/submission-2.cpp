class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp table of size n x 2 (0 for sell state, 1 for buy state)
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int currIdx = n-1; currIdx>=0; currIdx--){
            for(int buy = 0; buy<=1; buy++){
                if (buy == 1) {
                    // Choice 1: Buy today (subtract price) and look to sell next day
                    int pick = -prices[currIdx] + dp[currIdx + 1][0];
                    // Choice 2: Skip today
                    int notPick =  dp[currIdx + 1][1];
                    
                    dp[currIdx][buy] = max(pick, notPick);
                } else {
                    // Choice 1: Sell today (add price) and jump 2 days ahead due to COOLDOWN
                    int pick = prices[currIdx] + dp[currIdx + 2][1];
                    // Choice 2: Skip today
                    int notPick = dp[currIdx + 1][0];
                    
                    dp[currIdx][buy] = max(pick, notPick);
                }
            }
        }
        return dp[0][1];
    }
};
