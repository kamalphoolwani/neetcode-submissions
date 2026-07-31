class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                if(i>j)
                    continue;
                int maxm = INT_MIN;
                for(int ind = i; ind<=j; ind++){
                    int currCost = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                    maxm = max(currCost, maxm);
                }
                dp[i][j]=maxm;
            }
        }

        return dp[1][n];
    }   
};
