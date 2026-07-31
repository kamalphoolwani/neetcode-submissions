class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp table of size n x 2 (0 for sell state, 1 for buy state)
        vector<int> next1(2, 0), next2(2, 0);

        for(int currIdx = n-1; currIdx>=0; currIdx--){
            vector<int> curr(2, 0);
            for(int buy = 0; buy<=1; buy++){
                if (buy == 1) {
                    // Choice 1: Buy today (subtract price) and look to sell next day
                    int pick = -prices[currIdx] + next1[0];
                    // Choice 2: Skip today
                    int notPick =  next1[1];
                    
                    curr[buy] = max(pick, notPick);
                } else {
                    // Choice 1: Sell today (add price) and jump 2 days ahead due to COOLDOWN
                    int pick = prices[currIdx] + next2[1];
                    // Choice 2: Skip today
                    int notPick = next1[0];
                    
                    curr[buy] = max(pick, notPick);
                }
            }
            next2 = next1;
            next1 = curr;
        }
        return next1[1];
    }
};
