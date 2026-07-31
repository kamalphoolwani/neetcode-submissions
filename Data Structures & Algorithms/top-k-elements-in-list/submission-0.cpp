class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // if I sort then pair up : nlogn
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> temp;
        temp.push_back({1, nums[0]});
        for(int i = 1; i<n; i++){
            if(nums[i]==temp.back().second)
                temp.back().first++;
            else
                temp.push_back({1, nums[i]});
        }

        sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        vector<int> ans;

        int i = 0;
        while(k--){
            ans.push_back(temp[i++].second);
        }
        
        return ans;

    }
};
