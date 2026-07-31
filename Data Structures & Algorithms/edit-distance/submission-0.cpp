class Solution {
    int func(int idx1, int idx2, string &word1, string &word2, vector<vector<int>> &dp){
        if(idx2<0)
            return idx1+1;
        if(idx1<0)
            return idx2+1;
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if(word1[idx1] == word2[idx2])
            return dp[idx1][idx2] = func(idx1-1, idx2-1, word1, word2, dp);
        //insert
        int insert = 1+ func(idx1, idx2-1, word1, word2, dp);
        //delete
        int del = 1 + func(idx1-1, idx2, word1, word2, dp);
        //replace
        int replace = 1+ func(idx1-1, idx2-1, word1, word2, dp);

        return  dp[idx1][idx2] = min({insert, del, replace});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n-1, m-1, word1, word2, dp);
    }
};
