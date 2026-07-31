class Solution {
    int helper(int ind, vector<int>& cost, vector<int> &dp){
        if(ind==0 || ind==1)
            return cost[ind];
        if(dp[ind]!=-1)
            return dp[ind];
        int curr = (ind<cost.size())?cost[ind]:0;
        int oneJump = helper(ind-1, cost, dp);
        int twoJump = helper(ind-2, cost, dp);
        return dp[ind] = curr + min(oneJump, twoJump);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return helper(n, cost, dp);
    }
};
