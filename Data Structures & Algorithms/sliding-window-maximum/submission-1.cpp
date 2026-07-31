class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; // Will store indices of elements in monotonically decreasing order
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            // 1. Remove indices that are out of the current window's bounds
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // 2. Maintain monotonic property: remove smaller elements from the back
            // because they can never be the maximum anymore
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // 3. Add current element's index to the deque
            dq.push_back(i);
            
            // 4. Once the window is fully formed (size >= k), record the maximum
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};