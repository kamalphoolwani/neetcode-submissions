class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        int start = 0, maxLen = 0;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // After the loop, l and r are one step out of bounds
            int len = r - l - 1;
            if (len > maxLen) {
                maxLen = len;
                start = l + 1;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);     // Odd length palindromes (center is a char)
            expand(i, i + 1); // Even length palindromes (center is between chars)
        }

        return s.substr(start, maxLen);
    }
};
