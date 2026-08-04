class Solution {
    int func(int left, int right, vector<int>& piles,  vector<vector<int>> &dp){
        if(left == right)
            return piles[left];
        
        if(dp[left][right] != -1)
            return dp[left][right];
        int a = 0, b = 0;
        if((left+right)%2){
            a = max(piles[left] - func(left+1, right, piles, dp) , piles[right] - func(left, right-1, piles, dp));
        }
        else {
            b = max(piles[left] - func(left+1, right, piles, dp) , piles[right] - func(left, right-1, piles, dp));
        }
        return dp[left][right] = a - b;
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if(func(0, n-1, piles, dp)>0)
            return true;
        return false;
    }
};