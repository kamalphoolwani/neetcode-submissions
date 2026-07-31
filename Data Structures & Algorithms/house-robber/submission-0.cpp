class Solution {
    int func(int ind, vector<int> nums, vector<int> &dp){
        if(ind==0)
            return nums[ind];
        if(dp[ind]!=-1)
            return dp[ind];
        int pick = nums[ind] + ((ind>=2)? func(ind-2, nums, dp):0);
        int notPick = func(ind-1, nums, dp);

        return dp[ind] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return func(n-1,nums, dp);
    }
};
