class Solution {
    int robHelper(vector<int>& nums, int st, int end) {
        int n = end;
        int prev1 = nums[st], prev2 = nums[st];
        for(int ind=st; ind<=end; ind++){
            int pick = nums[ind] + ((ind>=st+2)? prev2:0);
            int notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[0], nums[1]);
       return max(robHelper(nums, 0, n-2), robHelper(nums, 1, n-1));
    }
};
