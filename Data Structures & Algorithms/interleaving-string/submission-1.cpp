class Solution {
    bool func(int idx1, int idx2, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        if(idx1<0 && idx2<0)
            return true;
        if(idx1<0){
            for(int i = 0; i<=idx2; i++){
                if(s2[i]!=s3[i])
                    return false;
            }
            return true;
        }
        if(idx2<0){
            for(int i = 0; i<=idx1; i++){
                if(s1[i]!=s3[i])
                    return false;
            }
            return true;
        }
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        bool fromS1 = false, fromS2 = false;
        if(s1[idx1]==s3[idx1+idx2+1])
            fromS1 = func(idx1-1, idx2, s1, s2, s3, dp);
        
        if(s2[idx2]==s3[idx1+idx2+1])
            fromS2 = func(idx1, idx2-1, s1, s2, s3, dp);
        
        return dp[idx1][idx2] = fromS1 || fromS2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n = s3.size();

        if(n1+n2 != n)
            return false;

        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return func(n1-1, n2-1, s1, s2, s3, dp);
    }
};
