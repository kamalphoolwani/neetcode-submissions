class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c) { return tolower(c); });

        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum((unsigned char)s[i])) i++;
            while (i < j && !isalnum((unsigned char)s[j])) j--;

            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
