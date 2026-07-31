class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // next1 represents day + 1, next2 represents day + 2
        // index 1: Buy state, index 0: Sell state
        vector<int> next1(2, 0), next2(2, 0);

        for (int currIdx = n - 1; currIdx >= 0; currIdx--) {
            vector<int> curr(2, 0);

            // Explicitly calculate for Buy state (buy == 1)
            int buyPick = -prices[currIdx] + next1[0];
            int buyNotPick = next1[1];
            curr[1] = max(buyPick, buyNotPick);

            // Explicitly calculate for Sell state (buy == 0)
            int sellPick = prices[currIdx] + next2[1];
            int sellNotPick = next1[0];
            curr[0] = max(sellPick, sellNotPick);

            // Slide our window backwards
            next2 = next1;
            next1 = curr;
        }

        return next1[1]; // Return the max profit on Day 0 starting in a Buy state
    }
};
