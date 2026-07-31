class Solution {
    // Change dp to 2D: dp[coin_index][current_amount]
    int func(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(ind == 0){
            if(amount % coins[ind] == 0) return amount / coins[ind];
            return 1e9;
        }
        
        // Check both index and amount
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notPick = func(ind - 1, coins, amount, dp);
        int pick = 1e9;
        if(coins[ind] <= amount){
            pick = 1 + func(ind, coins, amount - coins[ind], dp);
        }
        
        return dp[ind][amount] = min(pick, notPick);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Initialize 2D DP: rows = coins, cols = amount + 1
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(n - 1, coins, amount, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};