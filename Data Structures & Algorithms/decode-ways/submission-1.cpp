class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        dp[n] = 1;

        for(int i=n-1; i>=0; i--){
            if (s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            // CHOICE 1: Take one digit
            int ways = dp[i + 1];

            // CHOICE 2: Take two digits
            // Check if we have at least 2 chars left and if they form 10-26
            if (i + 1 < n) {
                int twoDigit = (s[i] - '0') * 10 + (s[i+1] - '0');
                if (twoDigit >= 10 && twoDigit <= 26) {
                    ways += dp[i + 2];
                }
            }
            dp[i] = ways;
        }

        return dp[0];
    }
};
