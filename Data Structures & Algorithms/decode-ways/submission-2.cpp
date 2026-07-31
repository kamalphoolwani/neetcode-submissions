class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        int next1 = 1, next2 = 1;

        for(int i=n-1; i>=0; i--){
            int curr;
            if (s[i] == '0'){
                curr = 0;
                next2 = next1;
                next1 = curr;
                continue;
            }
            // CHOICE 1: Take one digit
            curr = next1;

            // CHOICE 2: Take two digits
            // Check if we have at least 2 chars left and if they form 10-26
            if (i + 1 < n) {
                int twoDigit = (s[i] - '0') * 10 + (s[i+1] - '0');
                if (twoDigit >= 10 && twoDigit <= 26) {
                    curr += next2;
                }
            }
            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};
