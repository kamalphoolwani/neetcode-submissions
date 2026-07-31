class Solution {
    int helper(int ind, int prevInd, int &n,vector<int>& nums, vector<vector<int>> &dp){
        if(ind==n)
            return 0;
        if(dp[ind+1][prevInd+1] != -1)
            return dp[ind+1][prevInd+1];
        int pick = 0, notPick = 0; 
        if(prevInd==-1 || nums[ind]>nums[prevInd])
            pick = 1 + helper(ind+1, ind, n, nums, dp);

        notPick = helper(ind+1, prevInd, n, nums, dp);

        return dp[ind+1][prevInd+1]=max(pick, notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(0, -1, n, nums, dp);
    }
};
