class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> mp(26, 0);
        int l = 0, r = 0;
        int maxLen = 0, maxFreq = 0;
        while(r<n){
            mp[s[r]-'A']++;
            maxFreq = max(maxFreq, mp[s[r]-'A']);
            int len = r - l + 1;
            if(len - maxFreq > k){
                mp[s[l]-'A']--;
                l++;
            }
            maxLen = max(r - l + 1, maxLen);
            r++;
        }
        return maxLen;
    }
};
