class Solution {
    bool func(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {
        // Base Case: Both strings are fully consumed
        if (i == 0 && j == 0) return true;

        if (dp[i][j] != -1) return dp[i][j];

        bool fromS1 = false, fromS2 = false;

        // Choice 1: Match current character of s3 with s1 (if s1 has characters left)
        if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
            fromS1 = func(i - 1, j, s1, s2, s3, dp);
        }

        // Choice 2: Match current character of s3 with s2 (if s2 has characters left)
        if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
            fromS2 = func(i, j - 1, s1, s2, s3, dp);
        }

        return dp[i][j] = fromS1 || fromS2;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n = s3.size();

        if (n1 + n2 != n) return false;

        // DP table size is (n1 + 1) x (n2 + 1) to handle the 0 (empty) states safely
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return func(n1, n2, s1, s2, s3, dp);
    }
};