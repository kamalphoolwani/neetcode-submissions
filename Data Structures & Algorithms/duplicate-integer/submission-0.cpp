class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &itr: nums){
            if(st.find(itr)!=st.end())
                return true;
            st.insert(itr);
        }
        return false;
    }
};