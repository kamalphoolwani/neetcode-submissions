class Solution {
    int func(int idx1, int idx2, string &s, string &t, vector<vector<int>> &dp){
        if(idx2<0)
            return 1;
        if(idx1<0)
            return 0;
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        int pick = 0, notPick = 0;
        if(s[idx1]==t[idx2])
            pick = func(idx1-1, idx2-1, s, t, dp);

        notPick = func(idx1-1, idx2, s, t, dp);
        
        return dp[idx1][idx2] = pick + notPick;
    }
public:
    int numDistinct(string s, string t) {
        int idx1 = s.size()-1, idx2 = t.size()-1;
        vector<vector<int>> dp(idx1+1, vector<int>(idx2+1, -1));
        return func(idx1, idx2, s, t, dp);
    }
};
