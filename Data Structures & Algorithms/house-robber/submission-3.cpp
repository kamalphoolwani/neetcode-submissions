class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0], prev2 = nums[0];
        for(int ind=1; ind<n; ind++){
            int pick = nums[ind] + ((ind>=2)? prev2:0);
            int notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
