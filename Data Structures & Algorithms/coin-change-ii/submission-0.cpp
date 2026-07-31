class Solution {
    int helper(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(idx==0){
            if(amount%coins[idx]==0)
                return 1;
            return 0;
        }
        if(dp[idx][amount]!=-1)
            return dp[idx][amount];

        int pick = 0, notPick = 0;
        if(coins[idx]<=amount){
            pick = helper(idx, amount-coins[idx], coins, dp);
        }
        notPick = helper(idx-1, amount, coins, dp);
        return dp[idx][amount] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return helper(n-1, amount, coins, dp);
    }
};
