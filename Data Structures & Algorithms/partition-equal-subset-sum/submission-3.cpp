class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return false;
        
        int tSum = accumulate(nums.begin(), nums.end(), 0);

        if(tSum%2)
            return false;
        tSum = tSum/2;

        vector<bool> curr(tSum+1, false), prev(tSum+1, false);

        curr[0] = 1;
        if(nums[0]<=tSum)
            prev[nums[0]] = 1;
        
        for(int ind = 1; ind<n; ind++){
            for(int totalSum = 1; totalSum<=tSum; totalSum++){
                bool pick = false, notPick = false;
                if(nums[ind]<=totalSum)
                    pick = prev[totalSum-nums[ind]];
                
                notPick = prev[totalSum];
                curr[totalSum]= pick || notPick;
            }
            prev = curr;
        }

        return prev[tSum];
    }
};
