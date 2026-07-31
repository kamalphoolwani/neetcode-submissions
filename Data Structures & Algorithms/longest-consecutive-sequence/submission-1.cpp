class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Quick edge case guard
        
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        // Micro-optimization: Iterate through the SET, not the vector
        for (int num : st) {
            // Check if 'num' is the start of a sequence
            if (st.count(num - 1) == 0) {
                int next = num + 1;
                int count = 1;
                
                while (st.count(next)) {
                    count++;
                    next++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
