class Solution {
    int func(int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &dp){
        if(idx1 < 0 || idx2 < 0) {
            return 0;
        }
        if( dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        // CASE 1: The characters match! 
        // We take 1 point and securely move BOTH pointers backward.
        if(text1[idx1] == text2[idx2]) {
            return dp[idx1][idx2] = 1 + func(idx1 - 1, idx2 - 1, text1, text2, dp);
        }
        
        // CASE 2: The characters do not match.
        // We try shrinking text1 OR shrinking text2, and take the best outcome.
        return  dp[idx1][idx2] = max(
            func(idx1, idx2 - 1, text1, text2, dp), // Skip current char of text2
            func(idx1 - 1, idx2, text1, text2, dp)  // Skip current char of text1
        );
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return func(n1-1, n2-1, text1, text2, dp);
    }
};
