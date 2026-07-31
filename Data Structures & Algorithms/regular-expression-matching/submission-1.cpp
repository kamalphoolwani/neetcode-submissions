class Solution {
    int func(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i==0 and j==0)
            return true;
        if(j==0 and i>0)
            return false;
        if(i==0 and j>0){
            if(j>=2 and p[j-1]=='*')
                return func(i, j-2, s, p, dp);
            return false;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(p[j-1]=='*'){
            if (j < 2) return dp[i][j] = false;
            bool skip = func(i, j-2, s, p, dp);
            bool repeat = false;
            if(j >= 2 && (p[j-2] == s[i-1] || p[j-2] == '.')){
                repeat = func(i-1, j, s, p, dp);
            }
            return dp[i][j] = (skip || repeat);
        }

        if(s[i-1]==p[j-1] || p[j-1]=='.')
            return dp[i][j] = func(i-1, j-1, s, p, dp);

        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return func(n, m, s, p, dp);
    }
};
