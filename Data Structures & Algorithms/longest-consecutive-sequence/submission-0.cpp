class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            int count = 1;

            if(st.count(nums[i]-1)==0){
                int next = nums[i] + 1;
                while(st.count(next)){
                    count++;
                    next++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
