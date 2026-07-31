class Solution {

public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for(int tar = 1; tar<=target; tar++){
             int ans = 0;

            for(int i = 0; i<nums.size(); i++)
            {
                if(nums[i]<=tar)
                    ans += dp[tar-nums[i]];
            }
            dp[tar] = ans;
        }
        return dp[target];
    }
};