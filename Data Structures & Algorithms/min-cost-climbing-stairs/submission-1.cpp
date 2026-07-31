class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<=n; i++){
            int curr = (i<n)?cost[i]:0;
            dp[i] = curr + min(dp[i-1], dp[i-2]);
        }
        return dp[n];
    }
};
