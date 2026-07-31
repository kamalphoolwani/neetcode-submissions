class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i<n; i++){
            while(!dq.empty() and nums[dq.back()] <= nums[i])
                dq.pop_back();
            while(!dq.empty() and dq.front() <= i-k)
                dq.pop_front();
            dq.push_back(i);

            if(i+1-k>=0){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
