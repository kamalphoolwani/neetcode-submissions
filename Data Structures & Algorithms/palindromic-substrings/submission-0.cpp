class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        int count = 0;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }   
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);     // Odd length palindromes (center is a char)
            expand(i, i + 1); // Even length palindromes (center is between chars)
        }

        return count;
    }
};
