class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxm  = nums[0];
        int minm = nums[0];
        int ans = nums[0];
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(nums[i]<0)
                swap(minm, maxm);
            maxm = max(nums[i], maxm * nums[i]);
            minm = min(nums[i], minm * nums[i]);

            // Update the global maximum
            ans = max(ans, maxm);
        }
        return ans;
    }
};
