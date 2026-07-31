class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm = prices[0];
        int ans = 0;
        for(int i = 0; i<prices.size(); i++){
            ans = max(ans, prices[i]-minm);
            minm = min(minm, prices[i]);
        }

        return ans;
    }
};
