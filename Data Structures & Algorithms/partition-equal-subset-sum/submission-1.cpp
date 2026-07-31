class Solution {
    bool func(int ind, int totalSum, vector<int> &nums, vector<vector<int>> &dp){
        if(totalSum==0)
            return true;
        if(ind==0)
            return nums[ind]==totalSum;

        if(dp[ind][totalSum]!=-1)
            return dp[ind][totalSum];
        bool pick = false, notPick = false;
        if(nums[ind]<=totalSum)
            pick = func(ind-1, totalSum-nums[ind], nums, dp);
        
        notPick = func(ind-1, totalSum, nums, dp);

        return dp[ind][totalSum]=pick || notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return false;
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(totalSum%2)
            return false;
        totalSum = totalSum/2;
        vector<vector<int>> dp(n, vector<int>(totalSum+1, -1));
        return func(n-1, totalSum, nums, dp);
    }
};
