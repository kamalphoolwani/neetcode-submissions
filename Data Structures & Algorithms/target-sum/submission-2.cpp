class Solution {
    int helper(int idx, int targetSum, vector<int>& nums, vector<vector<int>> &dp){
        if(idx==0){
            if(nums[idx]==0 and targetSum==0)
                return 2;
            else if(targetSum==nums[idx] || targetSum==0)
                return 1;
            return 0;
        }

        if(dp[idx][targetSum] != -1)
            return dp[idx][targetSum];
        int pick = 0, notPick = 0;
        if(nums[idx]<=targetSum)
            pick = helper(idx-1, targetSum-nums[idx], nums, dp);
        notPick = helper(idx-1, targetSum, nums, dp);

        return dp[idx][targetSum] = pick + notPick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int tSum = target + totalSum;
        if(tSum%2)
            return 0;
        tSum = tSum/2;
        vector<vector<int>> dp(n, vector<int> (tSum+1, -1));
        return helper(n-1, tSum, nums, dp);
    }
};
