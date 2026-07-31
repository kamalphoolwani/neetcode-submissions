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
        
        int tSum = accumulate(nums.begin(), nums.end(), 0);

        if(tSum%2)
            return false;
        tSum = tSum/2;

        vector<vector<bool>> dp(n, vector<bool>(tSum+1, false));

        for(int i = 0; i<n; i++)
            dp[i][0] = 1;
        if(nums[0]<=tSum)
            dp[0][nums[0]] = 1;
        
        for(int ind = 1; ind<n; ind++){
            for(int totalSum = 1; totalSum<=tSum; totalSum++){
                bool pick = false, notPick = false;
                if(nums[ind]<=totalSum)
                    pick = dp[ind-1][totalSum-nums[ind]];
                
                notPick = dp[ind-1][totalSum];
                dp[ind][totalSum]= pick || notPick;
            }
        }

        return dp[n-1][tSum];
    }
};
