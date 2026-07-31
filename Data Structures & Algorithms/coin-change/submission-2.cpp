class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Initialize 2D DP: rows = coins, cols = amount + 1
        vector<int> prev(amount + 1, 1e9), curr(amount+1, 1e9);
        for(int amt = 0; amt<=amount; amt++){
            if(amt%coins[0]==0)
                prev[amt] = amt/coins[0];
        }

        for(int ind=1; ind<n; ind++){
            curr[0] = 0;
            for(int amt = 1; amt<=amount; amt++){
                int notPick = prev[amt];
                int pick = 1e9;
                if(coins[ind] <= amt){
                    pick = 1 + curr[amt - coins[ind]];
                }
                
                curr[amt] = min(pick, notPick);
            }
            prev = curr;
        }
        int ans = prev[amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};