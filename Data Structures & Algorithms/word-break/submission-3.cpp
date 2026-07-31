class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        dp[n] = true;
        for(int ind = n-1; ind>=0; ind--){
            for(int i = ind; i<n; i++){
                if(st.find(s.substr(ind, i -ind+1)) != st.end()){
                    if(dp[i+1]){
                        dp[ind] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};
